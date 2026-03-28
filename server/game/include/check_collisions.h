#pragma once

#include <set>

#include "types.h"
#include "ant.h"

/// Find all ants that are on the same tile. These ants should be killed
std::set<AntID> get_colliding_ants(const AntMap&);
