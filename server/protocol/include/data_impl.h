#pragma once

#include "data.h"
#include "glaze/glaze.hpp"

template <>
struct glz::meta<ObserverTurn> {
    using T = ObserverTurn;
    static constexpr auto value = glz::object(
        &T::alive_ants,
        &T::alive_hills,
        &T::alive_food,
        &T::alive_players,
        &T::turn_num
    );
};

template <>
struct glz::meta<ObserverInit> {
    using T = ObserverInit;
    static constexpr auto value = glz::object(
        &T::players,
        &T::map,
        &T::spawn_positions
    );
};

template <>
struct glz::meta<PlayerTurn> {
    using T = PlayerTurn;
    static constexpr auto value = glz::object(
        &T::alive_ants,
        &T::alive_hills,
        &T::alive_food,
        &T::food_count,
        &T::turn_num
    );
};

template <>
struct glz::meta<PlayerInit> {
    using T = PlayerInit;
    static constexpr auto value = glz::object(
        &T::map,
        &T::spawn_positions,
        &T::my_id
    );
};

static_assert(glz::reflectable<Move>);
static_assert(glz::reflectable<Moves>);
