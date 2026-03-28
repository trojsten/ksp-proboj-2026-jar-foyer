#pragma once

#include "point.h"
#include "map.h"
#include <vector>

/// Sample random locations, where new food should be spawned.
std::vector<Point> get_new_food_locations(int, const Map&);
