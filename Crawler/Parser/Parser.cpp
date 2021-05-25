#include "Parser.h"

void Parser::extract_new_links(GumboNode* node, std::vector<std::string>& extractedLinks) 
{
    if (node->type != GUMBO_NODE_ELEMENT) 
    {
        return;
    }

    GumboAttribute* href;
    if (node->v.element.tag == GUMBO_TAG_A && (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) 
    {
        std::string temp = std::string(href->value);
        if(temp.size() > 0)
        {
            // std::cout << "download link: " << href->value << std::endl;  // to print all links from current page
            extractedLinks.push_back(std::string(href->value));
        }      
    }

    GumboVector* children = &node->v.element.children;

    for (unsigned int i = 0; i < children->length; ++i) 
    {
        extract_new_links(static_cast<GumboNode*>(children->data[i]), extractedLinks);
    }
}