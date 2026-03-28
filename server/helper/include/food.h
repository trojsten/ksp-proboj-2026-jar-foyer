#pragma once

#include "point.h"
#include "types.h"

#include "glaze/glaze.hpp"

struct Food {
  public:
    Food(Point position) : position(position), id(++id_counter) {}
    Point get_position() const { return position; }
    FoodID get_id() const { return id; }
    auto operator<=>(const Food &other) const { return id <=> other.id; }

  private:
    friend struct glz::meta<Food>;

    Point position;
    FoodID id;
    static inline FoodID id_counter = FoodID(0);
};

template <>
struct glz::meta<Food> {
    using T = Food;
    static constexpr auto value = glz::object(&T::position, &T::id);
};

struct FoodComparator {
    using is_transparent = void;
    bool operator()(const Food &a, const Food &b) const { return a < b; }
    bool operator()(const Food &a, const FoodID &b) const {
        return a.get_id() < b;
    }
    bool operator()(const FoodID &a, const Food &b) const {
        return a < b.get_id();
    }
};
