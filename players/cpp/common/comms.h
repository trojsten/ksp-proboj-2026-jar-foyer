#pragma once

#include "data.h"
#include <map>
#include <string>
#include <vector>

struct PlayerTurn {
    std::map<ShadeID, Shade> alive_ants;
    std::set<Tombstone> alive_hills;
    std::set<Person> alive_food;
    int food_count;
    int turn_num;
};

struct PlayerInit {
    Map map;
    std::set<Tombstone> spawn_positions;
    PlayerID my_id;
};

struct Moves {
    std::vector<Move> data;
};

void init_world(World &);
void update_world(World &);
std::string serialize_moves(const Moves &);
