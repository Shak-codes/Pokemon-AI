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

    if (moveEffects.isBind()) {
      std::cout << "\n|--- is a binding move";
      basicMove = false;
    }
    if (moveEffects.isCharge()) {
      std::cout << "\n|--- is a charge move";
      basicMove = false;
    }
    if (moveEffects.isDrain()) {
      std::cout << "\n|--- is a health draining move";
      basicMove = false;
    }
    if (moveEffects.isFixed()) {
      std::cout << "\n|--- is a fixed damage move";
      basicMove = false;
    }
    if (moveEffects.isLocked()) {
      std::cout << "\n|--- is a locking move";
      basicMove = false;
    }
    if (moveEffects.isHealing()) {
      std::cout << "\n|--- is a healing move";
      basicMove = false;
    }
    if (moveEffects.isMultistrike()) {
      std::cout << "\n|--- is a multistrike move";
      basicMove = false;
    }
    if (moveEffects.isRecoil()) {
      std::cout << "\n|--- is a recoil move";
      basicMove = false;
    }
    if (moveEffects.isSpecial()) {
      std::cout << "\n|--- is a special move";
      basicMove = false;
    }
    if (moveEffects.affectsOpponentStats()) {
      std::cout << "\n|--- is a move that alters the opponent's stats";
      basicMove = false;
    }
    if (moveEffects.affectsUserStats()) {
      std::cout << "\n|--- is a move that alters the user's stats";
      basicMove = false;
    }
    if (moveEffects.affectsOpponentStatus()) {
      std::cout << "\n|--- is a move that affects the opponent's status";
      basicMove = false;
    }
    if (moveEffects.affectsUserStatus()) {
      std::cout << "\n|--- is a move that affects the user's status";
      basicMove = false;
    }
    if (moveEffects.isFlinch()) {
      std::cout << "\n|--- is a flinching move";
      basicMove = false;
    }
    if (moveEffects.isCritical()) {
      std::cout << "\n|--- is a move with a high critical ratio";
      basicMove = false;
    }
    if (moveEffects.isSemiInvulnerable()) {
      std::cout << "\n|--- is a semi-invulnerable move";
      basicMove = false;
    }
    if (moveEffects.isRecharge()) {
      std::cout << "\n|--- is a recharging move";
      basicMove = false;
    }
    if (moveEffects.isField()) {
      std::cout << "\n|--- is a field move";
      basicMove = false;
    }
    if (moveEffects.isPriority()) {
      std::cout << "\n|--- is a priority move";
      basicMove = false;
    }
    if (basicMove) {
      std::cout << " is a basic move";
    }
    std::cout << "\n";
  }

  std::cout << "All Effects tests passed!" << std::endl;
  return 0;
}
