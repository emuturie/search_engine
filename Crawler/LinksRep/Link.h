#ifndef LINK
#define LINK

#include "LinkStatus.h"
#include <string>

class Link 
{
private:
  std::string url;
  std::string domain;
  LinkStatus status;

public:
  Link();

  Link(const std::string& url, const std::string& domain, const LinkStatus& status);

  std::string getUrl() const;
  std::string getDomain() const;
  LinkStatus getStatus() const;
};

#endif
