#ifndef LOADER
#define LOADER

#include <curl/curl.h>
#include <string>
#include <iostream>

class Loader
{
private:
    std::string html;
    long code;

    static size_t writeFunction(char *ptr, size_t size, size_t nmemb, void* data);
public:
    Loader();
    Loader(std::string& html, long code);

    Loader loadHtml(const std::string& url);
   
    std::string getHtml();
    long getCode();
};

#endif
