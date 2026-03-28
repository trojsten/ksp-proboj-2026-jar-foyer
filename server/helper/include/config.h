#pragma once

#include "types.h"
#include <string>

struct PlayerConfig {
    PlayerConfig(std::string&& name) : name(std::move(name)), id(++id_counter) {}
    std::string name;
    PlayerID id;
    static inline PlayerID id_counter = PlayerID(0);
};
