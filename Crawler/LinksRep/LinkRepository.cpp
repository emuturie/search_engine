#include "LinkRepository.h"
#include <iostream>

std::optional<Link> LinkRepository::getByUrl(const std::string& newLink)
{
  for(auto& link : allLinks)
  {
    if(link.getUrl() == newLink)
    {
      //std::cout << "url in source: " << link.getUrl() << "\n";
      //std::cout << "url in newlink: " << newLink << "\n";
      return std::make_optional(link);
    }
  }

  return {};
}

std::vector<Link> LinkRepository::getBy(const std::string& domain, const LinkStatus& status, int counter)
{
    std::vector<Link> source;
    for(int i = 0; i < allLinks.size(); ++i)
    {
        if(allLinks[i].getDomain() == domain && allLinks[i].getStatus() == status)
        {
            source.push_back(allLinks[i]);
        }
    }
    return source;
}

void LinkRepository::saveLink(const Link& link)
{
  for(int i = 0; i < allLinks.size(); ++i)
  {
    if(allLinks[i].getUrl() == link.getUrl())
    {
      allLinks[i] = link;
      return;
    }
  }

  allLinks.push_back(link);
}

int LinkRepository::getSize() 
{
  return allLinks.size();
}