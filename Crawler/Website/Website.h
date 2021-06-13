#ifndef WEBSITE
#define WEBSITE

#include <string>

class Website 
{
private:
  std::string domain;
  std::string homepage;

public:
  Website(const std::string& domain, const std::string& homepage);

  std::string getDomain();
  std::string getHomepage();
};

#endif
