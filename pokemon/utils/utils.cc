#include "utils.h"

#include <random>

bool doesMoveHit(const Move& move) {
  float effectiveAccuracy = move.getAcc();

  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(0.0, 1.0);

  return dis(gen) < effectiveAccuracy;
}
