#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

#include "../lib/json.hpp"
#include "../pokemon/constants/enums.h"
#include "../pokemon/moves/move.h"
#include "../pokemon/utils/utils.h"

using json = nlohmann::json;

std::pair<double, double> confidenceInterval(double probability, int trials,
                                             double z_score = 1.96) {
  double mean = trials * probability;
  double std_dev = std::sqrt(trials * probability * (1 - probability));

  double lower_bound = mean - (z_score * std_dev);
  double upper_bound = mean + (z_score * std_dev);

  lower_bound /= trials;
  upper_bound /= trials;

  return {lower_bound, upper_bound};
}

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
  bool specialMove = false;
  Move normal_move = Move("Normal Move", normal, physical, opponent, 20, 1.00,
                          15, specialMove);
  Move special_move = Move("Special Move", normal, special, opponent, 20, 1.00,
                           15, specialMove);
  Move none_cat_move =
      Move("No Category", normal, none, opponent, 20, 1.00, 15, specialMove);
  Move opponent_move = Move("Normal Move", normal, physical, opponent, 20, 1.00,
                            15, specialMove);
  Move self_move = Move("Normal Move", normal, physical, opponent, 20, 1.00, 15,
                        specialMove);
  // Move buff_move = Move("Buff Move", normal, 60, 20, buff);
  // Move debuff_move = Move("Debuff Move", normal, 60, 20, debuff);
  // Move status_move = Move("Status Move", normal, 60, 20, status);
  // Move pure_status_move = Move("Normal Move", normal, 0, 20, status);

  assert(normal_move.getName() == "Normal Move" && ("Failure! (name)"));
  assert(normal_move.getType() == normal && ("Failure! (type)"));
  assert(normal_move.getCat() == physical && ("Failure! (physical category)"));
  assert(normal_move.getTarget() == opponent && ("Failure! (opponent target)"));
  assert(normal_move.getPwr() == 20 && ("Failure! (power)"));
  assert(normal_move.getAcc() == 1.00 && ("Failure! (accuracy)"));
  assert(normal_move.getPP() == 15 && ("Failure! (pp)"));
  // assert(normal_move.getEffect() == Effect::NONE && ("Failure! (no
  // effect)")); assert(buff_move.getEffect() == Effect::BUFF && ("Failure!
  // (buff)")); assert(debuff_move.getEffect() == Effect::DEBUFF && ("Failure!
  // (debuff)")); assert(status_move.getEffect() == Effect::STATUS && ("Failure!
  // (status)")); assert(status_move.pureStatus() == false && ("Failure! (non
  // pure-status)")); assert(pure_status_move.pureStatus() == true && ("Failure!
  // (pure-status)"));

  std::ifstream file("../data/moves.json");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  // Parse the JSON file
  json moves;
  file >> moves;

  // Close the file
  file.close();

  for (auto& [key, moveData] : moves.items()) {
    Move move = createMoveFromJson(moveData);

    if (move.getSpecial()) continue;

    int total_trials = 1000;
    int success = 0;

    if (move.getAcc() == 1.0) {
      for (int i = 0; i < total_trials; ++i) {
        if (doesMoveHit(move)) success++;
      }
      assert(success == total_trials ||
             (std::cerr << "Failure for " << move.getName()
                        << " which should always hit" << std::endl,
              false));
      continue;
    }

    auto interval = confidenceInterval(move.getAcc(), total_trials);
    int inside = 0;

    for (int i = 0; i < total_trials; ++i) {
      success = 0;
      for (int j = 0; j < total_trials; ++j) {
        if (doesMoveHit(move)) success++;
      }

      double percentage = static_cast<double>(success) / total_trials;
      if (percentage >= interval.first && percentage <= interval.second) {
        inside++;
      }
    }

    double inside_percentage = static_cast<double>(inside) / total_trials * 100;
    assert((inside_percentage >= 92 && inside_percentage <= 98) ||
           (std::cerr << "Failure! " << move.getName() << std::endl, false));
  }

  return 0;
}