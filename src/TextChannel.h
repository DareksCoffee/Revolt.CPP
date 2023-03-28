#pragma once
#include "Channel.h"

namespace RevoltCPP {

class Message;
class Embed;

class TextChannel : public Channel {
   public:
    std::string topic;e
    std::string last_message_id;
    std::string last_pin_timestamp;
    int rate_limit_per_user = 0;

    DLL_EXPORT TextChannel(const json& data, const std::string& token);
    DLL_EXPORT TextChannel(const std::string& id, const std::string& token);
    DLL_EXPORT TextChannel(const TextChannel& old);
    DLL_EXPORT TextChannel(){};

    DLL_EXPORT Message send(const std::string& content, const bool tts = false);
    DLL_EXPORT Message send(Embed embed);

    DLL_EXPORT std::vector<std::shared_ptr<Message>> history(const int limit = 100, const std::string& before = "", const std::string& after = "", const std::string& around = "");

    DLL_EXPORT void delete_messages(const std::vector<std::shared_ptr<Message>>& messages);
};

}