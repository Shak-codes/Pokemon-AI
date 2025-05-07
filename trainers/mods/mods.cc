#include <stdio.h>

#include <functional>
#include <vector>

#include "../../pokemon/constants/type-matchups.h"
#include "../../pokemon/moves/move.h"
#include "../../pokemon/pokemon.h"
#include "../constants/enums.h"

using Mod = std::function<void(std::vector<Move>, std::vector<int>, Pokemon*,
                               Pokemon*)>;

void mod1(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  for (auto& move : moves) {
    if (move.status() && opponent->getStatus().hasEffect()) {
      priority[idx] += 5;
    }
    idx++;
  }
}

void mod2(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  for (auto& move : moves) {
    Effects effects = move.getEffects();
    std::string special = effects.getSpecial();
    if (effects.affectsUserStats() || effects.affectsOpponentStats() ||
        effects.isField() || special == "conversion" || special == "haze" ||
        special == "transform" || special == "alwaysHit") {
      priority[idx] -= 1;
    }
    idx++;
  }
}

void mod3(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  for (auto& move : moves) {
    Type atkType = move.getType();
    std::vector<Type> opponentTypes = opponent->getTypes();
    double effectiveness = 1.0;
    for (auto& defType : opponentTypes) {
      effectiveness *= typeMatchups[{atkType, defType}];
    }
    if (effectiveness > 1)
      priority[idx] -= 1;
    else
      priority[idx] += 1;

    idx++;
  }
}