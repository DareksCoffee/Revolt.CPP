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
    ///the channel the message was sent in
    TextChannel* channel = NULL;
    ///The author of this message
    User* author = NULL;
    ///The content of this message
    std::string content;
    //ISO8601 timestamp
    ///when the message was created
    std::string timestamp;
    //ISO8601 timestamp
    ///when the message was edited
    std::string edited_timestamp;
    ///true, if this is a tts message
    bool tts;
    ///true, if everyone is mentioned
    bool mention_everyone;
    ///array of mentioned users
    std::vector<User*> mentions;
    //vector<Role> mention_roles;
    //vector<Attachments> attachments;
    ///Array of embeds
    std::vector<Embed*> embeds;
    //vector<Reaction> reactions;
    ///true, if this message has been pinned
    bool pinned;
    ///the webhook id, if the message was generated by a webhook
    std::string webhook_id;  //snowflake
    ///the type of the messsage
    int type;
    //MessageAcivity activity;
    //MessageApplication application;

    DLL_EXPORT Message(const json& data, const std::string& token);
    DLL_EXPORT Message(const Message& old);
    DLL_EXPORT Message();
    DLL_EXPORT ~Message();

    ///Edit this message
    DLL_EXPORT Message edit(const std::string& content);
    ///Delete this message
    DLL_EXPORT void delete_msg();
};

}  // namespace DiscordCPP
