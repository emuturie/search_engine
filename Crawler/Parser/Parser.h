#ifndef PARSER
#define PARSER

#include "gumbo.h"
#include <vector>
#include <string>

class Parser
{
public:
    void extract_new_links(GumboNode* node, std::vector<std::string>& extractedLinks);
};

#endif
