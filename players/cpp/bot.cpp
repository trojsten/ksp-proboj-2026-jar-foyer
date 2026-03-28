#include "common/bot.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Bot::init(const World& world) {
    cerr << "This appears in the log file" << endl;
    return;
}

vector<Point> directions = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

vector<Move> Bot::get_turn(const World& world) {
    vector<Move> moves;
    for(auto &[id, shade] : world.alive_shades) {
        if(shade.owner == world.my_id) {
            moves.push_back({id, shade.position + directions[rand() % 4]});
        }
    }
    return moves;
}
