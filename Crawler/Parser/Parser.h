#include "gumbo.h"
#include <iostream>
#include <vector>
#include <string>

class Parser
{
public:
    void extract_new_links(GumboNode* node, std::vector<std::string>& extractedLinks);
};