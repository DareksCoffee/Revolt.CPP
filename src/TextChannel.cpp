#include "TextChannel.h"

#include "Embed.h"
#include "Exceptions.h"
#include "Message.h"

RevoltCPP::Message RevoltCPP::TextChannel::send(const std::string& content, const bool tts) {
    std::string url = "/channels/" + id + "/messages";

    return Message(api_call(url, "POST", data, "application/json"), _token);
}
RevoltCPP::Message RevoltCPP::TextChannel::send(RevoltCPP::Embed embed) {
    std::string url = "/channels/" + id + "/messages";

    json data = {{"embed", embed.to_json()}};

    return Message(api_call(url, "POST", data, "application/json"), _token);
}
std::vector<std::shared_ptr<RevoltCPP::Message>> RevoltCPP::TextChannel::history(const int limit, const std::string& before, const std::string& after, const std::string& around) {
    std::vector<std::shared_ptr<Message>> ret;


    if (before.length() > 0)
        url += "&before=" + before;
    if (after.length() > 0)
        url += "&after=" + after;
    if (around.length() > 0)
        url += "&around" + around;

    json msgs = api_call(url, "GET", json(), "", false);

    for (json msg : msgs) {
        ret.push_back(std::make_shared<Message>(Message(msg, _token)));
    }

    return ret;
}


void RevoltCPP::TextChannel::delete_messages(const std::vector<std::shared_ptr<Message>>& messages) {
    if (messages.size() < 2)
        throw SizeError("Cannot delete less than 2 messages: use Message::delete_msg() instead");
    else if (messages.size() > 100)
        throw SizeError("Cannot delete more than 100 messages");

    std::string url = "/channels/" + id + "/messages/bulk-delete";

    json data = {{"messages", json::array()}};
    for (unsigned int i = 0; i < messages.size(); i++) {
        data["messages"].emplace_back(messages[i]->id);
    }

    api_call(url, "POST", data, "application/json");
}