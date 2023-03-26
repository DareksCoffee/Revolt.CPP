#pragma once
#include <iostream>
#include <map>

#include "static.h"

namespace RevoltCPP {

class RevoltObject {
   private:
    struct http_response {
        unsigned int status_code;
        std::map<std::string, std::string> headers;
        std::string body;
    };
    http_response request_internal(const std::string& url, const std::string& method = "GET", const std::string& data = "", const std::string& content_type = "");

   protected:
    ///token to authentificate with the revolt api
    std::string _token;

    ///helper function to communicate with the http api
    json api_call(const std::string& url, const std::string& method = "GET", const json& data = json(), const std::string& content_type = "", const bool cache = true);

   public:
    ///the id of the object
    std::string id;  //snowflake

    DLL_EXPORT RevoltObject(){};
    ///	@param[in]	token	Revolt token
    DLL_EXPORT RevoltObject(const std::string& token);
};

} 
