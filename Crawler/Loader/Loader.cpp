#include "Loader.h"

Loader::Loader()
    : html{}, code{}
{
}

Loader::Loader(std::string& html, long code)
    : html{html}, code{code}
{
}

size_t Loader::writeFunction(char *ptr, size_t size, size_t nmemb, void* data) 
{
    std::string* str = (std::string*)data;
    str->append(ptr, size * nmemb);
    return size * nmemb;
}

Loader Loader::loadHtml(const std::string& url)
{
    CURL *curl = curl_easy_init(); 
    CURLcode result;

    if(!curl)
    {
        std::cout << "init error\n";
        return {};
    }

    std::string* html = new std::string;
    long responseCode;

    curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)html);

    result = curl_easy_perform(curl); //400 300 200
    if(result != CURLE_OK || result == CURLE_TOO_MANY_REDIRECTS)
    {
        std::cout << "Error\n";
        return Loader();
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
    curl_easy_cleanup(curl);
    
    return Loader(*html, responseCode);
}

std::string Loader::getHtml() 
{
    return html;
}

long Loader::getCode() 
{
    return code;
}