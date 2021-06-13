#include <iostream>
#include <string>
#include <vector>

#include "Loader/Loader.h"
#include "Website/Website.h"
#include "LinksRep/LinkRepository.h"
#include "Parser/Parser.h"

int main() 
{
  std::vector<Website> websites;
  LinkRepository linkrep;
  Loader loader;
  Parser parse;

  //websites.push_back(Website("ru.wikipedia.org", "https://ru.wikipedia.org/wiki/SCP_Foundation"));
  websites.push_back(Website("noexisting.org", "https://noexisting.org"));
  for(auto& website : websites)
  {
    Loader loadd = loader.loadHtml(website.getHomepage());

        long status = loadd.getCode();
        if(status < 200 || status >= 300)
        {

          std::cout << "website doesnt exist\n";
           continue;
        }

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

          std::cout << "Skiping the link";
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
          
          linkrep.saveLink( Link(newLink, website.getDomain(), LinkStatus::WAITING) );
          std::cout << "newLink: " << newLink << "\n";
        }

        linkrep.saveLink(Link(link.getUrl(), link.getDomain(), LinkStatus::SUCCESS));
      }

      std::cout << "links in source now: " << linkrep.getSize() << "\n";
    }
  }
} 