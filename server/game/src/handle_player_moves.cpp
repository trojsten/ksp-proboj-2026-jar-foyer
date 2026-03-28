#include "game.h"
#include "constants.h"

using namespace std;

void Game::handle_player_moves(const Player& player, const Moves& moves) {
    set<AntID> moved_ants;
    for(auto [ant_id, new_position] : moves.data) {
        if(alive_ants.find(ant_id) == alive_ants.end()) {
            cerr << "Ant " << str(ant_id) << " does not exist" << endl;
            continue;
        }
        if(moved_ants.find(ant_id) != moved_ants.end()) {
            cerr << "Ant " << str(ant_id) << " has already moved" << endl;
            continue;
        }
        Ant &ant = alive_ants[ant_id];
        if(ant.get_owner() != player.get_id()) {
            cerr << "Can not move ant " << str(ant_id) << ": ant does not belong to " << player.get_name() << endl;
            continue;
        }
        moved_ants.insert(ant_id);

        move_ant(ant_id, new_position);
    }
}

void Game::move_ant(AntID ant_id, Point destination) {
    Ant &ant = alive_ants[ant_id];
    if((ant.get_position() - destination).dist2() > ANT_MOVE_RADIUS2) {
        cerr << "Ant " << str(ant.get_id()) << " tried to move too far" << endl;
        return;
    }
    if(!world_map.can_move_to(destination)) {
        cerr << "Ant " << str(ant.get_id()) << " tried to move to an invalid position" << endl;
        return;
    }

    ant.set_position(destination);
}
