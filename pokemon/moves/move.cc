#include "move.h"

#include "../../lib/json.hpp"
#include "../constants/enums.h"

using json = nlohmann::json;

Move::Move(const json& moveData)
    : name(moveData["name"]),
      type(stringToType(moveData["type"])),
      category(stringToCategory(moveData["category"])),
      power(moveData["power"]),
      accuracy(moveData["accuracy"]),
      maxPP(moveData["pp"]),
      pp(moveData["pp"]),
      effects(moveData["name"], moveData["effects"]) {}

std::string Move::getName() const { return name; }

Type Move::getType() const { return type; }

Category Move::getCategory() const { return category; }

int Move::getPower() const { return power; }

float Move::getAccuracy() const { return accuracy; }

int Move::getPP() const { return pp; }

void Move::decrementPP() { pp--; }

void Move::restorePP(const int value) { pp = std::clamp(pp + value, 0, maxPP); }

bool Move::status() const { return !power && effects.hasEffect(); }

Effects Move::getEffects() const { return effects; }