#include "Embed.h"

#include "Exceptions.h"
#include "Logger.h"

RevoltCPP::Embed::Embed(const std::string& title, const std::string& description){
    _title = title;
    _description = description;
}
RevoltCPP::Embed::Embed(const json& data) {
    _title = get_or_else<std::string>(data, "title", "");
    _description = get_or_else<std::string>(data, "description", "");
    _type = get_or_else<std::string>(data, "type", "");
    _url = get_or_else<std::string>(data, "url", "");
    _timestamp = get_or_else<std::string>(data, "timestamp", "");
    _color = get_or_else<int>(data, "color", -1);
}
    if (has_value(data, "video")) {
        json video = data.at("video");

        _video.width = get_or_else<int>(video, "width", 0);
        _video.height = get_or_else<int>(video, "height", 0);
        _video.url = get_or_else<std::string>(video, "url", "");
    }
    if (has_value(data, "author")) {
        json author = data.at("author");

        _author.name = get_or_else<std::string>(author, "name", "");
        _author.url = get_or_else<std::string>(author, "url", "");
        _author.icon_url = get_or_else<std::string>(author, "icon_url", "");
        _author.proxy_icon_url = get_or_else<std::string>(author, "proxy_icon_url", "");
    }


    if (has_value(data, "fields")) {
        for (json field : data.at("fields")) {
            Field f;
            field.at("name").get_to<std::string>(f.name);
            field.at("value").get_to<std::string>(f.value);
            field.at("inline").get_to<bool>(f.is_inline);

            _fields.push_back(f);
        }
    }


void RevoltCPP::Embed::set_color(int color) {
    _color = color;
}

void RevoltCPP::Embed::add_field(const std::string& name, const std::string& value, bool Inline) {
    if (_fields.size() >= 25) {
        throw SizeError("Embed: Cannot add more than 25 fields.");
    }

    Field field;
    field.name = name;
    field.value = value;
    field.is_inline = Inline;
    _fields.push_back(field);
}

void RevoltCPP::Embed::set_author(const std::string& name, const std::string& url, const std::string& icon_url) {
    _author.name = name;
    _author.url = url;
    _author.icon_url = icon_url;
}


void RevoltCPP::Embed::set_image(const std::string& url) {
    _image.url = url;
}

json RevoltCPP::Embed::to_json() {
    json ret;

    if (_title.length() > 0)
        ret["title"] = _title;
    if (_description.length() > 0)
        ret["description"] = _description;

    if (_color >= 0)
        ret["color"] = _color;

    for (unsigned int i = 0; i < _fields.size(); i++) {
        json f;
        f["name"] = _fields[i].name;
        f["value"] = _fields[i].value;
        f["inline"] = _fields[i].is_inline;
        ret["fields"].emplace_back(f);
    }

    if (_author.name.length() > 0) {
        ret["author"]["name"] = _author.name;
        ret["author"]["url"] = _author.url;
        ret["author"]["icon_url"] = _author.icon_url;
    }

    if (_image.url.length() > 0)
        ret["image"]["url"] = _image.url;

    if (_video.url.length() > 0)
        ret["video"]["url"] = _video.url;

    if (ret.size() == 0) {
        throw SizeError("Cannot create JSON from empty Embed");
    }

    return ret;
}
