#pragma once

#include <set>
#include <vector>
#include "ant.h"
#include "hill.h"
#include "types.h"

/// Find all hills, that are occupied by enemy ant.
///
/// Returns pairs of hill and player, that razed the hill.
std::vector<std::tuple<HillID, PlayerID>> mark_razed_hills(const AntMap&, const std::set<Hill,HillComparator>&);
