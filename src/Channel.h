#pragma once
#include <iostream>
#include <optional>
#include <vector>

#include "RevoltObject.h"

namespace RevoltCPP {
namespace ChannelType {
enum ChannelType {
    SERVER_TEXT,
    DM,
    SERVER_VOICE,
    GROUP_DM,
    SERVER_CATEGORY,
};
}

class User;
class Revolt;

class Channel : public RevoltObject {
   public:
    
    int type;
    int32_t position;
    std::string name;
    std::string icon;

    DLL_EXPORT Channel(const json& data, const std::string& token);
    DLL_EXPORT Channel(const std::string& id, const std::string& token);
    DLL_EXPORT Channel(const Channel& old);
    DLL_EXPORT Channel(){};

    DLL_EXPORT static Channel* from_json(Revolt* client, const json& data, const std::string& token);

    ///Delete this channel
    DLL_EXPORT void delete_channel();

    template <class T>
    DLL_EXPORT Channel* copy(T obj);

    ///@return Channelname as std::string
    DLL_EXPORT operator std::string() { return name; };
};

template <class T>
inline Channel* Channel::copy(T obj) {
    T* derivedptr = new T(obj);
    Channel* baseptr = dynamic_cast<Channel*>(derivedptr);
    if (baseptr != NULL) {
        return baseptr;
    }
    // this will be reached if T is not derived from Base
    delete derivedptr;
    throw std::string("Invalid type given to Clone");
}

} 