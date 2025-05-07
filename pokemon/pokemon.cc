// Pokemon.cpp
#include "pokemon.h"

#include "../lib/json.hpp"
#include "constants/enums.h"

using json = nlohmann::json;

Pokemon::Pokemon(const json& pokemon)
    : name(std::move(name)), stats(std::move(stats)), moves(std::move(moves)) {}

std::string Pokemon::getName() const { return name; }

std::vector<Type> Pokemon::getTypes() const { return types; }

Status Pokemon::getStatus() const { return status; }

int Pokemon::getStat(const std::string& stat) const {
  return stats.getStats()[stat];
}

std::vector<Move> Pokemon::getMoves() const { return moves; }

void Pokemon::reset() {
  status = StatusEffect::None;
  currentHP = stats.getStats()["health"];
  for (Move& move : moves) {
    move.restorePP(64);
  }
  itemsUsed - 0;
}

void Pokemon::incItemsUsed() { itemsUsed += 1; }

int Pokemon::getItemsUsed() const { return itemsUsed; }

int Pokemon::getCurrentHP() const { return currentHP; }

void Pokemon::incSwitches() { switches += 1; }

int Pokemon::getSwitches() const { return switches; }
