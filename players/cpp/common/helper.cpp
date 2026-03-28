#include "data.h"
#include "constants.h"

Point Point::operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
}

long long Point::dist2() const {
    return (long long) x * x + (long long) y * y;
}

std::vector<Point> Point::get_visible() const {
    int max_delta = 0;
    while (max_delta * max_delta < constants::SHADE_BATTLE_RADIUS2) max_delta++;

    std::vector<Point> result;

    for (int dx = -max_delta; dx <= max_delta; dx++) {
        for (int dy = -max_delta; dy <= max_delta; dy++) {
            Point dp{dx, dy};
            if (dp.dist2() <= constants::SHADE_BATTLE_RADIUS2) {
                result.push_back(*this + dp);
            }
        }
    }

    return result;
}

bool Map::is_inside(const Point& p) const {
    return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
}

bool Map::can_move_to(const Point& p) const {
    return is_inside(p) && water_tiles.find(p) == water_tiles.end();
}

int Shade::get_fear(const std::map<Point, Shade>& shade_positions) const {
    int fear = 0;
    for (const Point& visible : position.get_visible()) {
        auto it = shade_positions.find(visible);
        if (it != shade_positions.end() && it->second.owner != owner) {
            fear ++;
        }
    }
    return fear;
}

std::map<ShadeID, int> Shade::get_enemy_fears(const std::map<Point, Shade>& shade_positions) const {
    std::map<ShadeID, int> result;
    for (const Point& visible : position.get_visible()) {
        auto it = shade_positions.find(visible);
        if (it != shade_positions.end() && it->second.owner != owner) {
            result[it->second.id] = it->second.get_fear(shade_positions);
        }
    }
    return result;
}

bool Shade::will_i_die(const std::map<Point, Shade>& shade_positions) const {
    int fear = get_fear(shade_positions);

    auto enemy_fears = get_enemy_fears(shade_positions);

    for (const auto& [enemy, enemy_fear] : enemy_fears) {
        if (enemy_fear >= fear) {
            return true;
        }
    }

    return false;
}
