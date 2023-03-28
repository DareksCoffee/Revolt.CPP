#pragma once
#include <iostream>

#include "User.h"
#include "static.h"

namespace RevoltCPP {

class Member : public User {
   public:

    std::string nick;

    std::string joined_at; 

    bool deaf = false;

    bool mute = false;

    DLL_EXPORT Member(const json& data, const std::string& token);
    DLL_EXPORT Member(){};

    DLL_EXPORT operator std::string();
};

}