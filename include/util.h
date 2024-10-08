/*!
 
*/

#ifndef UTIL_H
#define UTIL_H

/*! Importation of librairies*/
#include <iostream>
#include <curl/curl.h>

/**
 * @brief Function to write response content to string
 *
 * @param ptr
 * @param size
 * @param nmemb
 * @param data String where response is written
 * @return size_t
 */
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data);

class curlHandler
{
private:
    CURL *curl_handle;

public:
    long response_code;
    double elapsed;
    std::string response_header;
    curlHandler()
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl_handle = curl_easy_init();
    }

    void get_page(const char *url, std::string &response_string, const std::string username = "");

    ~curlHandler()
    {
        curl_easy_cleanup(this->curl_handle);
        curl_global_cleanup();
    }
};
/**
 * @brief Gets the webpage as string for given url
 *
 * @param url The url to be fetched
 * @param response_string The response content from url
 * @param username Username which is passed to curl
 */
// void get_page(const char *url, std::string &response_string, const std::string username = "");

//size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

#endif