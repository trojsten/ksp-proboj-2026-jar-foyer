#include <iostream>
#include <string>
#include <utility>
#include "glaze/glaze.hpp"

#include "comms.h"
#include "data.h"

using namespace std;

constexpr string DELIM = ".";

string read_chunk() {
    string chunk, buf;
    while (getline(cin, buf)) {
        if (buf == DELIM) return chunk;
        chunk += buf + "\n";
    }
    std::unreachable();
}

void init_world(World &world) {
    auto chunk = read_chunk();
    auto ec = glz::read_json<PlayerInit>(chunk);
    if (!ec) {
        cerr << "Failed to parse PlayerInit " << glz::format_error(ec.error(), chunk) << endl;
        cerr << chunk << endl;
        throw runtime_error("Failed to parse PlayerInit");
    }
    PlayerInit init = std::move(ec.value());
    world.my_id = init.my_id;
    world.alive_tombstones = std::move(init.spawn_positions);
    world.map = std::move(init.map);
}

void update_world(World &world) {
    auto chunk = read_chunk();
    auto ec = glz::read_json<PlayerTurn>(chunk);
    if (!ec) {
        cerr << "Failed to parse PlayerTurn " << glz::format_error(ec.error(), chunk) << endl;
        throw runtime_error("Failed to parse PlayerTurn");
    }

    PlayerTurn turn = std::move(ec.value());
    world.converted_count = turn.food_count;
    world.turn = turn.turn_num;
    world.alive_shades = std::move(turn.alive_ants);
    world.alive_tombstones = std::move(turn.alive_hills);
    world.alive_people = std::move(turn.alive_food);
}

string serialize_moves(const Moves &moves) {
    auto ec = glz::write_json(moves);
    if (!ec) {
        cerr << "Failed to serialize moves " << glz::format_error(ec.error()) << endl;
        throw runtime_error("Failed to serialize moves");
    }
    return ec.value();
}
