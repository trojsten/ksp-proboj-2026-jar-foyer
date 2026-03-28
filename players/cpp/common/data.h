#pragma once

#include <map>
#include <set>
#include <vector>

struct Point {
    int x, y;
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    auto operator<=>(const Point&) const = default;
    long long dist2() const;
    /// Get the points that would be seen by a shade at this position
    std::vector<Point> get_visible() const;
};

typedef int ShadeID;
typedef int PlayerID;
typedef int TombstoneID;
typedef int PersonID;

struct Move {
    ShadeID id;
    Point target;
};

struct Map {
    int width, height;
    std::set<Point> water_tiles;
    std::set<Point> tombstone_positions;
    bool is_inside(const Point&) const;
    bool can_move_to(const Point&) const;
};

struct Shade {
    Point position;
    PlayerID owner;
    ShadeID id;

    /// Get the fear of this shade assuming the given placement of all shades
    int get_fear(const std::map<Point, Shade>& shade_positions) const;

    /// Get the fears of all enemy shades that this shade can see, assuming the given placement of all shades
    std::map<ShadeID, int> get_enemy_fears(const std::map<Point, Shade>& shade_positions) const;

    /// Determine whether this shade will die with the given placement of shades
    bool will_i_die(const std::map<Point, Shade>& shade_positions) const;

};

struct Tombstone {
    Point position;
    PlayerID owner;
    TombstoneID id;
    bool operator<(const Tombstone& other) const {
        return id < other.id;
    }
};

struct Person {
    Point position;
    PersonID id;
    auto operator<=>(const Person&) const = default;
};

///@brief Struct representing current game state
struct World {
    int my_id;
    int converted_count;
    int turn = 0;
    Map map;
    std::map<ShadeID, Shade> alive_shades;
    std::set<Tombstone> alive_tombstones;
    std::set<Person> alive_people;
};
