#include "DMChannel.h"

#include "User.h"
#include "static.h"

RevoltCPP::DMChannel::DMChannel(const json& data, const std::string& token) : RevoltCPP::TextChannel(data, token) {
    for (json recipient : data.at("recipients")) {
        recipients.push_back(User(recipient, token));
    }
    owner = new User(data.at("owner_id").get<std::string>(), token);
    application_id = get_or_else<std::string>(data, "application_id", "");
}

RevoltCPP::DMChannel::DMChannel(const std::string& id, const std::string& token) {
    _token = token;
    std::string url = "/channels/" + id;
    *this = DMChannel(api_call(url), token);
}

RevoltCPP::DMChannel::DMChannel(const DMChannel& old) : RevoltCPP::TextChannel(old) {
    for (unsigned int i = 0; i < old.recipients.size(); i++) {
        recipients.push_back(User(old.recipients[i]));
    }
    owner = new User(*old.owner);
    application_id = old.application_id;
}
