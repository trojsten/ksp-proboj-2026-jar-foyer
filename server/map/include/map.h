#pragma once

#include "point.h"
#include <optional>
#include <set>
#include <string>

#include "glaze/glaze.hpp"

struct Map {
  public:
    Map(int width, int height) : width(width), height(height) {}
    static std::optional<Map> from_ppm(const std::string &);
    bool inside(const Point &) const;
    bool can_move_to(const Point &) const;
    const std::set<Point> &get_water_tiles() const { return water_tiles; };
    const std::set<Point> &get_hill_positions() const { return tombstone_positions; }
    int get_width() const { return width; }
    int get_height() const { return height; }

  private:
    friend struct glz::meta<Map>;

    int width, height;
    std::set<Point> water_tiles;
    std::set<Point> tombstone_positions;
};

template <>
struct glz::meta<Map> {
    using T = Map;
    static constexpr auto value = glz::object(
            &T::width, &T::height, &T::water_tiles, &T::tombstone_positions);
};
