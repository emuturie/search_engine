#include "Link.h"

Link::Link()
  : url{}, domain{}, status{}
{
}

Link::Link(const std::string& url, const std::string& domain, const LinkStatus& status)
  : url{url}, domain{domain}, status{status}
{
}

std::string Link::getUrl() const 
{
   return url; 
}

std::string Link::getDomain() const 
{ 
  return domain; 
}

LinkStatus Link::getStatus() const 
{ 
  return status; 
}