#include "food_spawn_phase.h"
#include "constants.h"
#include "rng.h"
#include <random>

using namespace std;

int get_food_count_to_spawn(int current_food_count) {
    constexpr double MAX_SPAWN_REMAINDER_RATIO = .3;
    constexpr double NO_SPAWN_PROBABILITY = .3;
    constexpr double MASS_SPAWN_PROBABILIY = .02;

    int remainder = MAX_FOOD_COUNT - current_food_count;
    if (remainder == 0) {
        return 0;
    }
    std::uniform_real_distribution<> prob_dist(0, 1);
    if(prob_dist(rng) < MASS_SPAWN_PROBABILIY){
        return remainder;
    }
    if(prob_dist(rng) < NO_SPAWN_PROBABILITY) {
        return 0;
    }

    int max_spawn = ceil(MAX_SPAWN_REMAINDER_RATIO * remainder);

    std::uniform_int_distribution<> dist(1, max_spawn);
    return dist(rng);
}

vector<Point> get_new_food_locations(int alive_food_count, const Map& world_map) {
    vector<Point> food_locations;
    int to_spawn = get_food_count_to_spawn(alive_food_count);
    for (int i = 0; i < to_spawn; ) {
        int x = uniform_int_distribution<>(0, world_map.get_width() - 1)(rng);
        int y = uniform_int_distribution<>(0, world_map.get_height() - 1)(rng);
        if(world_map.can_move_to({x, y})){
            food_locations.push_back({x, y});
            i++;
        }
    }
    return food_locations;
}
