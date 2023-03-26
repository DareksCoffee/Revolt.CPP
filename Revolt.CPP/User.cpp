#include "User.h"

#include "DMChannel.h"
#include "Embed.h"
#include "Message.h"

RevoltCPP::User::User(const json& data, const std::string& token) : RevoltCPP::RevoltObject(token) {
    data.at("id").get_to<std::string>(id);
    data.at("username").get_to<std::string>(username);
    avatar = get_or_else<std::string>(data, "avatar", "");
    bot = get_or_else<bool>(data, "bot", false);
    locale = get_or_else<std::string>(data, "locale", "");
    verified = get_or_else<bool>(data, "verified", false);
    email = get_or_else<std::string>(data, "email", "");
    flags = get_or_else<int>(data, "flags", 0);
}

RevoltCPP::User::User(const std::string& id, const std::string& token) : RevoltCPP::DiscordObject(token) {
    std::string url = "/users/" + id;

    *this = User(api_call(url), token);
}

/** @return DMChannel
*/
RevoltCPP::DMChannel RevoltCPP::User::get_dmchannel() {
    json data = {{"recipient_id", id}};

    return DMChannel(api_call("/users/@me/channels", "POST", data), _token);
}

/**	@param[in]	content	The string message to send.
@param[in]	tts		(optional) Wether to send as tts-message or not. Default is false.
@return	The message that was sent.
*/
RevoltCPP::Message RevoltCPP::User::send(const std::string& content, const bool tts) {
    return Message(get_dmchannel().send(content, tts));
}

/**	@param[in]	embed	The Embed to send.
@return	The message that was sent.
*/
RevoltCPP::Message RevoltCPP::User::send(const RevoltCPP::Embed& embed) {
    return Message(get_dmchannel().send(embed));
}
