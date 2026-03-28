#pragma once

#include <utility>
#include <set>
#include <vector>
#include "types.h"
#include "ant.h"
#include "food.h"

/// Find all collected food.
///
/// Returns pairs of food and player, that claimed the food. If multiple players
/// tried to claim the same food, `PlayerID::None` is returned instead.
std::vector<std::pair<FoodID,PlayerID>> get_harvested_food(const AntMap &, const std::set<Food,FoodComparator> &);
