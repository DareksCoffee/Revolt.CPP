#pragma once
#include <iostream>

#include "Channel.h"
#include "RevoltObject.h"
#include "Member.h"
#include "User.h"

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace RevoltCPP {

namespace VerificationLevel {
enum VerificationLevel {
    NONE,
    LOW,
    MEDIUM,
    HIGH,
    VERY_HIGH
};
}

namespace DefaultMessageNotificationLevel {
enum DefaultMessageNotificationLevel {
    ALL_MESSAGES,
    ONLY_MENTIONS
};
}


namespace MFALevel {
enum MFALevel {
    NONE,
    ELEVATED
};
}

class User;
class Channel;
class Member;
class Revolt;

class Guild : public RevoltObject {
   public:

    std::string name;

    std::string icon;

    std::string splash;

    User* owner = NULL;

    int permissions = 0;

    std::string region;

 
    int afk_timeout = 0;
 
    bool embed_enabled = false;

    Channel* embed_channel = NULL;

    int verification_level = 0;

    int default_message_notifications = 0;

    int explicit_content_filter = 0;

    std::vector<std::string> features;

    int mfa_level = 0;

    std::string application_id; 

    bool widget_enabled = false;

    Channel* widget_channel = NULL;

    Channel* system_channel = NULL;

    std::string joined_at;  //ISO8601 timestamp
    bool large = false;
    bool unavailable = false;
    int member_count = 0;
    std::vector<Member*> members;
    std::vector<Channel*> channels;

    DLL_EXPORT Guild(Revolt* client, const json& data, const std::string& token);
    DLL_EXPORT Guild(Revolt* client, const std::string& id, const std::string& token);
    DLL_EXPORT Guild(const Guild& old);
    DLL_EXPORT Guild(){};
    DLL_EXPORT ~Guild();

    DLL_EXPORT void _add_channel(Channel* channel);
    DLL_EXPORT void _update_channel(Channel* channel);
    DLL_EXPORT void _remove_channel(const std::string& channel_id);
    DLL_EXPORT void _add_member(Member* member);
    DLL_EXPORT void _update_member(Member* member);
    DLL_EXPORT void _remove_member(const std::string& member_id);

    ///@return Guildname as std::string
    DLL_EXPORT operator std::string() { return name; };


    DLL_EXPORT void leave();

    DLL_EXPORT void delete_server();


    DLL_EXPORT void kick(const User& user);

    DLL_EXPORT void ban(const User& user, const std::string& reason, const int delete_message_days = 0);

    DLL_EXPORT void unban(const User& user);
};

}