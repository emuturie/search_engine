#include <iostream>
#include <string>
#include <vector>

#include <curl/curl.h>
#include "gumbo.h"

#include "Loader/Loader.h"
#include "Website/Website.h"
#include "LinksRep/LinkRepository.h"
#include "Parser/Parser.h"

void extract_new_links(GumboNode* node) 
{
    if (node->type != GUMBO_NODE_ELEMENT) 
    {
        std::cout << "not element\n";
        return;
    }

    GumboAttribute* href;
    if (node->v.element.tag == GUMBO_TAG_A && (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) 
    {
        std::string temp = std::string(href->value);
        if(temp.size() > 0)
        {
            std::cout << "download link: " << href->value << std::endl;  // to print all links from current page
        }      
    }

    GumboVector* children = &node->v.element.children;

    for (unsigned int i = 0; i < children->length; ++i) 
    {
        extract_new_links(static_cast<GumboNode*>(children->data[i]));
    }
}

int main() 
{
  std::vector<Website> websites;
  LinkRepository linkrep;
  Loader loader;
  Parser parse;

  websites.push_back(Website("rau.am", "https://rau.am/"));

  for(auto& website : websites)
  {
    linkrep.saveLink(Link(website.getHomepage(), website.getDomain(), LinkStatus::WAITING));

    while(true)
    {
      std::vector<Link> links = linkrep.getBy(website.getDomain(), LinkStatus::WAITING, 10);

      // there is no any links to crawle
      if(links.empty())
      {
        break;
      }

      // for(auto& link : links)
      // {
      //   std::cout << "URL: " << links.getUrl() << " Domain: " << link.getDomain() << "\n";
      // }
      
      for(auto& link : links)
      {
        // to get html code for each link
        Loader load = loader.loadHtml(link.getUrl());

        long status = load.getCode();
        if(status < 200 || status >= 300)
        {
           continue;
        }

        GumboOutput* output = gumbo_parse(load.getHtml().c_str());

        std::vector<std::string> extractedLinks;        
        
        parse.extract_new_links(output->root, extractedLinks);

        gumbo_destroy_output(&kGumboDefaultOptions, output); 

        // std::cout << "exLinksSize: " << extractedLinks.size() << "\n";

        std::cout << "size: " << linkrep.getSize() << "\n";
        for(const auto& newLink : extractedLinks)
        {
          if(linkrep.getByUrl(newLink).has_value())
          {
            // std::cout << newLink;
            // std::cout << "already exists current link\n";
            continue;
          }

          std::cout << "newLink: " << newLink << "\n";
          linkrep.saveLink( Link(newLink, website.getDomain(), LinkStatus::WAITING) );
        }

        linkrep.saveLink(Link(link.getUrl(), link.getDomain(), LinkStatus::SUCCESS));
      }

      std::cout << "links in source now: " << linkrep.getSize() << "\n";
    }
  }
} 