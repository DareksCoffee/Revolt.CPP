#pragma once
#include <iostream>

#include "RevoltObject.h"

namespace RevoltCPP {

namespace MessageType {
enum MessageType {
    DEFAULT,
    RECIPIENT_ADD,
    RECIPIENT_REMOVE,
    CALL,
    CHANNEL_NAME_CHANGE,
    CHANNEL_ICON_CHANGE,
    CHANNEL_PINNED_MESSAGE,
    GUILD_MEMBER_JOIN
};
}

class User;
class TextChannel;
class Embed;

class Message : public RevoltObject {
   public:
    TextChannel* channel = NULL;

    User* author = NULL;

    std::string content;

    std::string timestamp;

    std::string edited_timestamp;

    std::vector<User*> mentions;

    std::vector<Embed*> embeds;

    bool pinned;

    int type;

    DLL_EXPORT Message(const json& data, const std::string& token);
    DLL_EXPORT Message(const Message& old);
    DLL_EXPORT Message();
    DLL_EXPORT ~Message();

    DLL_EXPORT Message edit(const std::string& content);
    DLL_EXPORT void delete_msg();
};

}