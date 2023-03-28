#pragma once
#include <iostream>

#include "RevoltObject.h"
#include "Logger.h"

namespace RevoltCPP {

class Message;
class Embed;
class DMChannel;

class User : public RevoltObject {

    std::string username;


    std::string avatar;

    bool bot = false;

    bool mfa_enabled = false;

    std::string locale;

    bool verified = false;

    std::string email;

    int flags = 0;


    DLL_EXPORT User() {}
    DLL_EXPORT User(const json& data, const std::string& token);
    DLL_EXPORT User(const std::string& id, const std::string& token);
    DLL_EXPORT virtual ~User() {}


    DLL_EXPORT DMChannel get_dmchannel();

    DLL_EXPORT Message send(const std::string& content, const bool tts = false);

    DLL_EXPORT Message send(const Embed& embed);


    DLL_EXPORT virtual operator std::string() { return username; };
};

}