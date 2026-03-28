#pragma once

#include <vector>
#include <set>
#include "ant.h"
#include "hill.h"
#include "point.h"
#include "types.h"

/// Get positions where new ants can be spawned for a given player, randomly
/// shuffled.
std::vector<Point> get_new_ant_pos(const std::set<HillID>&, const std::set<Hill, HillComparator>&, const AntMap&);
