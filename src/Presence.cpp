#include "Presence.h"

RevoltCPP::Presence::to_json(){
    json json = {
        {"name", name},
        {"description",description}
    };

    return json;
}