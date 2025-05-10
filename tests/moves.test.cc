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
  std::ifstream file("../data/moves.json");

  if (!file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  json moves;
  file >> moves;

  file.close();

  for (auto& [key, moveData] : moves.items()) {
    Move move{moveData};

    // Test accuracy
    int total_trials = 1000;
    int success = 0;

    if (move.getAccuracy() == 1.0) {
      for (int i = 0; i < total_trials; ++i) {
        if (doesMoveHit(move)) success++;
      }
      assert(success == total_trials ||
             (std::cerr << "Failure for " << move.getName()
                        << " which should always hit" << std::endl,
              false));
      continue;
    }

    auto interval = confidenceInterval(move.getAccuracy(), total_trials);
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

    // Test type
    assert(move.getType() == stringToType(moveData["type"]));

    // Test category
    assert(move.getCategory() == stringToCategory(moveData["category"]));
    if (move.getCategory() == Category::Status) {
      assert(move.status());
    }

    // Test power
    int power = moveData["power"];
    assert(move.getPower() == power);

    // Test pp
    assert(move.getPP() == moveData["pp"]);
  }

  return 0;
}