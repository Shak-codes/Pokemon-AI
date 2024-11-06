#ifndef UTILS
#define UTILS

#include "../../lib/json.hpp"
#include "../constants/enums.h"
#include "../moves/move.h"

using json = nlohmann::json;

bool doesMoveHit(const Move& move);

Move createMoveFromJson(const json& moveData);

Type stringToType(const std::string& type);

#endif
