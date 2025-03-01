// Move.cpp
#include "move.h"

#include "../constants/enums.h"
#include "../../lib/json.hpp"

using json = nlohmann::json;

Move::Move(const json& moveData)
    : name(moveData["name"]),
      type(moveData["type"]),
      category(moveData["category"]),
      target(moveData["target"]),
      power(moveData["power"]),
      accuracy(moveData["accuracy"]),
      maxPP(moveData["pp"]),
      pp(moveData["pp"]),
      effects(moveData["effects"]) {}

std::string Move::getName() const { return name; }

Type Move::getType() const { return type; }

Category Move::getCategory() const { return category; }

int Move::getPower() const { return power; }

float Move::getAccuracy() const { return accuracy; }

int Move::getPP() const { return pp; }

void Move::decrementPP() { pp--; }

void Move::restorePP(const int value) { pp = std::clamp(pp + value, 0, maxPP)}

Effect Move::getEffect() const { return effect; }