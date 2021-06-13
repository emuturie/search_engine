#ifndef LINK
#define LINK

#include <string>

enum class LinkStatus {
  WAITING,
  ERROR,
  SUCCESS
};

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
