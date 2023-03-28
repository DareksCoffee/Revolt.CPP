#define version "0.5.17"

#define REVOLT_HOST "revolt.chat" 
#define API_PREFIX "api.revolt.chat" //wil

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#include <boost/asio/ssl/context.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

LL_EXPORT void hexchar(unsigned char c, unsigned char& hex1,
                        unsigned char& hex2);
DLL_EXPORT std::string urlencode(std::string s);

DLL_EXPORT void load_ssl_certificates(boost::asio::ssl::context& ssl_context);

DLL_EXPORT inline bool has_value(const json& j, const std::string& key) {
    return j.count(key) > 0 && !j.at(key).is_null();
}

template <class T>
DLL_EXPORT T get_or_else(const json& j, const std::string& key, const T& _default) {
    if (j.count(key) == 0 || j.at(key).is_null())
        return _default;
    else
        return j.at(key).get<T>();
}