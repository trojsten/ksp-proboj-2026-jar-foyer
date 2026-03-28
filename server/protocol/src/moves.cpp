#include "data.h"

#include "glaze/glaze.hpp"

using namespace std;

optional<Moves> Moves::from_sstream(stringstream &in) {
    auto res = glz::read_json<Moves>(in.str());
    if (res) {
        return std::move(*res);
    }

    std::cerr << glz::format_error(res.error(), in.str()) << endl;
	return std::nullopt;
}
