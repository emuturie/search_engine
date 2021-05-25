#include "Website.h"

Website::Website(const std::string& domain, const std::string& homepage) 
    : domain{domain}, homepage{homepage}
{
}  

std::string Website::getDomain() 
{ 
  return domain; 
}

std::string Website::getHomepage() 
{ 
  return homepage; 
}