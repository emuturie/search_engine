#ifndef LINK_REPOSITORY
#define LINK_REPOSITORY

#include "Link.h"
#include <vector>
#include <optional>

class LinkRepository
{
private:
    std::vector<Link> allLinks;
public:
    std::optional<Link> getByUrl(const std::string& newLink);

    std::vector<Link> getBy(const std::string& domain, const LinkStatus& status, int counter);
    
    void saveLink(const Link& link);

    int getSize();
};

#endif
