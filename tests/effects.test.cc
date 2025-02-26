#include "../pokemon/effects/effects.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
using json = nlohmann::json;

int main() {
  std::ifstream file("../data/moves.json");
  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  json moves;
  file >> moves;

  file.close();

  if (moves.empty()) {
    std::cerr << "Error: 'moves' JSON object is empty!" << std::endl;
    return 1;
  }

  std::cout << "Imported moves!" << std::endl;

  for (const auto& [moveName, moveData] : moves.items()) {
    std::cout << moveName;

    std::string name = moveName;
    Effects moveEffects{name, moveData["effects"]};
    bool basicMove = true;

    std::vector<std::pair<std::string, bool>> effectChecks = {
        {"affects the user's status", moveEffects.affectsUserStatus()},
        {"affects the opponent's status", moveEffects.affectsOpponentStatus()},
        {"affects the user's stats", moveEffects.affectsUserStats()},
        {"affects the opponent's stats", moveEffects.affectsOpponentStats()}};

    for (const auto& [description, condition] : effectChecks) {
      if (condition) {
        std::cout << "\n|----" << description;
        basicMove = false;
      }
    }

    if (moveEffects.isSpecial()) {
      std::cout << "\n|---- is a special move";
      basicMove = false;
    }

    if (basicMove) std::cout << " is a basic move";

    std::cout << std::endl;
  }

  std::cout << "All Effects tests passed!" << std::endl;
  return 0;
}
