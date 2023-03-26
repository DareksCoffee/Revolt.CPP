#include "GuildChannel.h"

#include "Guild.h"
#include "static.h"

RevoltCPP::GuildChannel::GuildChannel(const json& data, const std::string& token) : RevoltCPP::TextChannel(data, token) {
    if (has_value(data, "guild_id")) {
        guild = new Guild(NULL, data.at("guild_id").get<std::string>(), token);
    }

    if (has_value(data, "parent_id")) {
        parent = new Channel(data.at("parent_id").get<std::string>(), token);
    }
}

RevoltCPP::GuildChannel::GuildChannel(const std::string& id, const std::string& token) {
    _token = token;
    std::string url = "/channels/" + id;
    *this = GuildChannel(api_call(url), token);
}

RevoltCPP::GuildChannel::GuildChannel(const GuildChannel& old) : RevoltCPP::TextChannel(old) {
    if (old.guild != NULL)
        guild = new Guild(*old.guild);
    topic = old.topic;
    if (old.parent != NULL)
        parent = new Channel(*old.parent);
}

RevoltCPP::GuildChannel::~GuildChannel() {
    if (guild != NULL)
        delete guild;
    if (parent != NULL)
        delete parent;
}
