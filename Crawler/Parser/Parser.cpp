#include "Parser.h"
#include <iostream>
//#include <boost/regex.hpp>

/*std::vector<std::pair<std::string, std::string> > Parser::checkByDomain(std::vector<std::string>& links, const std::string& domain)
{
    std::vector<std::pair<std::string, std::string> >  newDomains;
    for(auto& link : links)
    { 
        boost::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
        boost::cmatch what;
        
        if(regex_match(link.c_str(), what, ex)) 
        {
            // std::string protocol = std::string(what[1].first, what[1].second);
            
            std::string currentDomain   = std::string(what[2].first, what[2].second);
            
            // std::string port     = std::string(what[3].first, what[3].second);
            // std::string path     = std::string(what[4].first, what[4].second);
            // std::string query    = std::string(what[5].first, what[5].second);

            if(currentDomain != domain)
            {                
                newDomains.push_back(std::make_pair(domain, link));
                std::cout << "[" << link << "]" << std::endl;
                std::cout << currentDomain << std::endl;
                std::remove(links.begin(), links.end(), link);
            }

            // std::cout << protocol << std::endl;
            // std::cout << port << std::endl;
            // std::cout << path << std::endl;
            // std::cout << query << std::endl;
        }
    }
    return newDomains;
}
*/

void Parser::extract_new_links(GumboNode* node, std::vector<std::string>& extractedLinks) 
{
    if (node->type != GUMBO_NODE_ELEMENT) 
    {
        return;
    }

    GumboAttribute* href;
    if (node->v.element.tag == GUMBO_TAG_A) 
    {
        href = gumbo_get_attribute(&node->v.element.attributes, "href");
        if (href)
        {
            std::string temp = std::string(href->value);
            if(temp.size() > 0)
            {
                // std::cout << "download link: " << href->value << std::endl;  // to print all links from current page
                extractedLinks.push_back(temp);
            }      
        }
    }

    GumboVector* children = &node->v.element.children;

    for (unsigned int i = 0; i < children->length; ++i) 
    {
        extract_new_links(static_cast<GumboNode*>(children->data[i]), extractedLinks);
    }
}