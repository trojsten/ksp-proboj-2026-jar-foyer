#pragma once

#include <set>
#include <optional>

#include "point.h"
#include "runner.h"
#include "types.h"
#include "ant.h"
#include "hill.h"
#include "food.h"
#include "data.h"
#include "map.h"

class Game {
public:
	/// @brief Create game from initial runner message
	static std::optional<Game> load_config();

	/// @brief Start game
	void run();

protected:
    Game(Map&& world_map) : world_map(std::move(world_map)), runner{} {};
	int current_turn = 0;
	AntMap alive_ants;
	std::set<PlayerID> alive_players;
	PlayerMap all_players;
	std::set<Hill, HillComparator> alive_hills;
	std::set<Food, FoodComparator> alive_food;
	std::map<PlayerID, std::set<HillID>> player_hills;

	Map world_map;
	Runner runner;

	void game_loop();
	void init();
	bool check_end();
	void cleanup();

	void kill_ant(AntID);
	void kill_hill(HillID, PlayerID);
	void kill_player(PlayerID);
	void harvest_food(FoodID, PlayerID);
	void move_ant(AntID, Point);

	void handle_player_moves(const Player&, const Moves&);
};
