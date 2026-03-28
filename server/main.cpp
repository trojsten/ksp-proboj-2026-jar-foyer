#include <iostream>
#include "game.h"

using namespace std;

int main(){
    auto game_result = Game::load_config();
    if(!game_result.has_value()) {
        cerr << "Failed to create game from config files" << endl;
        return 1;
    }
    Game game = std::move(game_result.value());
    game.run();
}
