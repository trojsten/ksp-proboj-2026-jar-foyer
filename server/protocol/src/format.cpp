#include "glaze/json.hpp"
#include "format.h"
#include "data.h"
#include <iostream>


using namespace std;

namespace format {

    string to_observer(const ObserverTurn& turn) {
        string buffer;
        auto err = glz::write_json(turn, buffer);

        if (err) {
            throw runtime_error("Failed to serialize ObserverTurn");
        }
        buffer += "\n\n";
        return buffer;
    }

    string init_observer(const ObserverInit& init) {
        string buffer;
        auto err = glz::write_json(init, buffer);

        if (err) {
            throw runtime_error("Failed to serialize ObserverInit");
        }
        buffer += "\n\n";
        return buffer;
    }

    string to_player(const PlayerTurn& turn) {
        string buffer;
        auto err = glz::write_json(turn, buffer);

        if (err) {
            throw runtime_error("Failed to serialize PlayerTurn");
        }
        buffer += '\n';
        return buffer;
    }

    string init_player(const PlayerInit& init) {
        string buffer;
        auto err = glz::write_json(init, buffer);

        if (err) {
            throw runtime_error("Failed to serialize PlayerInit");
        }
        buffer += '\n';
        return buffer;
    }

    string final_score(const map<string, int>& name_to_score) {
        stringstream ret;
        for(const auto &[name, score] : name_to_score) {
            ret << name << " " << score << "\n";
        }
        return ret.str();
    }
}
