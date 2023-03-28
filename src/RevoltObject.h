#pragma once
#include <iostream>
#include <map>

#include "static.h"


namespace RevoltCPP {
    private: 
        struct http_response{
            unsigned int status_code;
            std::map<std::string, std::string> headers;
            std::string body;
        };
    http_response request_internal(const std::string& url, const std::string& method = "GET", const std::string& data = "", const std::string& content_type = "");


    protected:
        std::string _token; 

        json api_call(const std::string& url, const std::string& method = "GET", const json& data = json(), const std::string& content_type = "", const bool cache = true);

        public:
            std::string _id;
            DLL_EXPORT RevoltObject(){};
            DLL_EXPORT RevoltObject(const std::string&_token);
}