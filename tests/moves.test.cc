#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
#include "../pokemon/constants/enums.h"
#include "../pokemon/moves/move.h"

using json = nlohmann::json;

int main() {
  // Effect no_effect = Effect::NONE;
  // Effect buff = Effect::BUFF;
  // Effect debuff = Effect::DEBUFF;
  // Effect status = Effect::STATUS;
  Category physical = Category::Physical;
  Category special = Category::Special;
  Category none = Category::None;
  Target opponent = Target::Opponent;
  Target self = Target::Self;
  Type normal = Type::Normal;
  Move normal_move =
      Move("Normal Move", normal, physical, opponent, 20, 1.00, 15);
  Move special_move =
      Move("Special Move", normal, special, opponent, 20, 1.00, 15);
  Move none_cat_move =
      Move("No Category", normal, none, opponent, 20, 1.00, 15);
  Move opponent_move =
      Move("Normal Move", normal, physical, opponent, 20, 1.00, 15);
  Move self_move =
      Move("Normal Move", normal, physical, opponent, 20, 1.00, 15);
  // Move buff_move = Move("Buff Move", normal, 60, 20, buff);
  // Move debuff_move = Move("Debuff Move", normal, 60, 20, debuff);
  // Move status_move = Move("Status Move", normal, 60, 20, status);
  // Move pure_status_move = Move("Normal Move", normal, 0, 20, status);

  assert(normal_move.getName() == "Normal Move" && ("Success! (name)"));
  assert(normal_move.getType() == normal && ("Success! (type)"));
  assert(normal_move.getCat() == physical && ("Success! (physical category)"));
  assert(normal_move.getTarget() == opponent && ("Success! (opponent target)"));
  assert(normal_move.getPwr() == 60 && ("Success! (power)"));
  assert(normal_move.getAcc() == 1.00 && ("Success! (accuracy)"));
  assert(normal_move.getPP() == 20 && ("Success! (pp)"));
  // assert(normal_move.getEffect() == Effect::NONE && ("Success! (no
  // effect)")); assert(buff_move.getEffect() == Effect::BUFF && ("Success!
  // (buff)")); assert(debuff_move.getEffect() == Effect::DEBUFF && ("Success!
  // (debuff)")); assert(status_move.getEffect() == Effect::STATUS && ("Success!
  // (status)")); assert(status_move.pureStatus() == false && ("Success! (non
  // pure-status)")); assert(pure_status_move.pureStatus() == true && ("Success!
  // (pure-status)"));

  std::ifstream file("../data/moves.json");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  // Parse the JSON file
  json moveData;
  file >> moveData;

  // Close the file
  file.close();

  // Iterate through each key-value pair
  for (auto& [key, value] : moveData.items()) {
    std::cout << "Move: " << key << std::endl;
    std::cout << "Type: " << value["type"] << " Category: " << value["category"]
              << " Target: " << value["target"] << " Power: " << value["power"]
              << " Accuracy: " << value["accuracy"] << " PP: " << value["pp"]
              << std::endl;
  }

  return 0;
}