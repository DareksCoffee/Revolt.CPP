#pragma once
#include <vector>

#include "Activity.h"
#include "Channel.h"
#include "DMChannel.h"
#include "RevoltObject.h"
#include "Embed.h"
#include "Exceptions.h"
#include "Guild.h"
#include "GuildChannel.h"
#include "Logger.h"
#include "MainGateway.h"
#include "Message.h"
#include "User.h"
#include "static.h"

namespace RevoltCPP {

class Revolt : public RevoltObject {
   protected:

    std::vector<std::shared_ptr<MainGateway>> _gateways;
    unsigned int _num_shards;

    User* _user;
    std::vector<Guild*> _guilds;

    friend std::shared_ptr<VoiceClient> VoiceChannel::connect();

    DLL_EXPORT std::shared_ptr<MainGateway> get_shard(const unsigned int shard_id);
    DLL_EXPORT Guild* get_guild(const std::string& guild_id);

    DLL_EXPORT void connect();

    DLL_EXPORT void on_websocket_incoming_message(const json& payload);
    DLL_EXPORT void handle_raw_event(const std::string& event_name, const json& data);

    virtual void on_ready(User user);
    virtual void on_message(Message message);
    virtual void on_user_ban(User user, Guild guild);
    virtual void on_user_unban(User user, Guild guild);
    virtual void on_user_join(Member member, Guild guild);
    virtual void on_user_remove(User user, Guild guild);
    virtual void on_typing_start(User user, TextChannel channel, unsigned int timestamp);

   public:
    Logger log;

    DLL_EXPORT Revolt(const std::string& token, const Intents& intents, const unsigned int num_shards = 0);
    DLL_EXPORT Revolt(const std::string& token, const Intents& intents, const unsigned int shard_id, const unsigned int num_shards);
    DLL_EXPORT virtual ~Revolt();


    DLL_EXPORT void start();


    DLL_EXPORT void update_presence(const std::string& status, const bool afk = false, const int shard_id = -1);
};

}