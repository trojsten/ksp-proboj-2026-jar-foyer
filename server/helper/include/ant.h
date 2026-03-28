#pragma once

#include "point.h"
#include "types.h"
#include <map>

#include "glaze/glaze.hpp"

struct Ant {
  public:
    Ant(Point position, PlayerID owner)
        : position(position), owner(owner), id(++id_counter) {}
    Ant() = default;
    Point get_position() const { return position; }
    void set_position(Point p) { position = p; }
    PlayerID get_owner() const { return owner; }
    AntID get_id() const { return id; }
    auto operator<=>(const Ant &other) const { return id <=> other.id; }

  private:
    friend struct glz::meta<Ant>;
    Point position;
    PlayerID owner;
    AntID id;
    static inline AntID id_counter = AntID(0);
};

template <>
struct glz::meta<Ant> {
    using T = Ant;
    static constexpr auto value = glz::object(&T::position, &T::owner, &T::id);
};

typedef std::map<AntID, Ant> AntMap;

/// @brief Insert ant into the map and consume it
void insert(AntMap &, Ant &&);
