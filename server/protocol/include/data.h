#pragma once

#include <functional>
#include <set>
#include <sstream>
#include <vector>

#include "ant.h"
#include "food.h"
#include "hill.h"
#include "map.h"
#include "player.h"
#include "point.h"
#include "types.h"

struct ObserverTurn {
    std::reference_wrapper<const AntMap> alive_ants;
    std::reference_wrapper<const std::set<Hill, HillComparator>> alive_hills;
    std::reference_wrapper<const std::set<Food, FoodComparator>> alive_food;
    std::reference_wrapper<const PlayerMap> alive_players;
    int turn_num;
};

struct ObserverInit {
    std::reference_wrapper<const PlayerMap> players;
    std::reference_wrapper<const Map> map;
    std::reference_wrapper<const std::set<Hill, HillComparator>>
            spawn_positions;
};

struct PlayerTurn {
    std::reference_wrapper<const AntMap> alive_ants;
    std::reference_wrapper<const std::set<Hill, HillComparator>> alive_hills;
    std::reference_wrapper<const std::set<Food, FoodComparator>> alive_food;
    int food_count;
    int turn_num;
};

struct PlayerInit {
    std::reference_wrapper<const Map> map;
    std::reference_wrapper<const std::set<Hill, HillComparator>>
            spawn_positions;
    PlayerID my_id;
};

struct Move {
    AntID id;
    Point target;
};

struct Moves {
    std::vector<Move> data;
    static std::optional<Moves> from_sstream(std::stringstream &);
};


#include "data_impl.h"
