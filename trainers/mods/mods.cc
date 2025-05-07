#include <stdio.h>

#include <functional>
#include <vector>

#include "../../pokemon/constants/type-matchups.h"
#include "../../pokemon/moves/move.h"
#include "../../pokemon/pokemon.h"
#include "../../utils.cc"
#include "../constants/enums.h"
#include "actions.h"

// REFACTOR LATER FOR CLEANER CODE
// struct SpecialBehaviour {
//   float hpThreshold;
//   int maxItems;
//   std::vector<std::pair<Actions, int>> actions;
//   int maxNumRange;
// };

void cat1(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  for (auto& move : moves) {
    if (move.status() && opponent->getStatus().hasEffect()) {
      priority[idx] += 5;
    }
    idx++;
  }
}

void cat2(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
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

void cat3(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  std::vector<double> effectivenessList;
  std::vector<Type> opponentTypes = opponent->getTypes();
  double max = 0.0;

  for (auto& move : moves) {
    Type atkType = move.getType();
    double effectiveness = 1.0;
    for (auto& defType : opponentTypes) {
      effectiveness *= typeMatchups[{atkType, defType}];
    }
    effectivenessList.push_back(effectiveness);
    if (effectiveness > max) max = effectiveness;
  }

  for (std::size_t i = 0; i < moves.size(); ++i) {
    if (effectivenessList[i] > 1.0) {
      priority[i] -= 1;
    }
    if (effectivenessList[i] < 1.0 && max >= 1.0) {
      priority[i] += 1;
    }
  }
}

Actions agatha(std::vector<Move> moves, std::vector<int> priority,
               Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed);
  int itemsUsed = user->getItemsUsed();
  if (num <= 5) return Actions::Switch;
  if (num <= 27 && itemsUsed < 2) return Actions::SuperPotion;
  return Actions::Attack;
}

Actions blackbelt(std::vector<Move> moves, std::vector<int> priority,
                  Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 200);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 2) return Actions::XAttack;
  return Actions::Attack;
}

Actions BlaineRB(std::vector<Move> moves, std::vector<int> priority,
                 Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 2) return Actions::SuperPotion;
  return Actions::Attack;
}

Actions BlaineY(std::vector<Move> moves, std::vector<int> priority,
                Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  if (num <= 25 && percentageHP < 0.1 && itemsUsed < 2)
    return Actions::SuperPotion;
  return Actions::Attack;
}

Actions Blue2(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 200);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && percentageHP < 0.2 && itemsUsed < 1) return Actions::Potion;
  return Actions::Attack;
}

Actions Blue3(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 200);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && percentageHP < 0.2 && itemsUsed < 1)
    return Actions::FullRestore;
  return Actions::Attack;
}

Actions Brock(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  bool statusAffliction = user->getStatus().hasEffect();
  int itemsUsed = user->getItemsUsed();
  if (statusAffliction && num <= 10 && itemsUsed < 5) return Actions::FullHeal;
  return Actions::Attack;
}

Actions CooltrainerGirl(std::vector<Move> moves, std::vector<int> priority,
                        Pokemon* user, Pokemon* opponent, int seed) {
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (percentageHP < 0.1 && itemsUsed < 1) return Actions::HyperPotion;
  if (percentageHP < 0.2 && itemsUsed < 1) return Actions::Switch;
  return Actions::Attack;
}

Actions CooltrainerBoy(std::vector<Move> moves, std::vector<int> priority,
                       Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 200);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 2) return Actions::Potion;
  return Actions::Attack;
}

Actions Erika(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (num <= 50 && percentageHP < 0.1 && itemsUsed < 1)
    return Actions::SuperPotion;
  return Actions::Attack;
}

Actions Giovanni(std::vector<Move> moves, std::vector<int> priority,
                 Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 1) return Actions::GuardSpec;
  return Actions::Attack;
}

Actions Juggler(std::vector<Move> moves, std::vector<int> priority,
                Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int switches = user->getSwitches();
  if (num <= 25 && switches < 3) return Actions::Switch;
  return Actions::Attack;
}

Actions KogaRB(std::vector<Move> moves, std::vector<int> priority,
               Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 2) return Actions::XAttack;
  return Actions::Attack;
}

Actions KogaY(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 200);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 2) return Actions::XAttack;
  return Actions::Attack;
}

Actions Lance(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 50 && itemsUsed < 1) return Actions::HyperPotion;
  return Actions::Attack;
}

Actions Lorelei(std::vector<Move> moves, std::vector<int> priority,
                Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (num <= 50 && percentageHP < 0.2 && itemsUsed < 2)
    return Actions::SuperPotion;
  return Actions::Attack;
}

Actions LtSurge(std::vector<Move> moves, std::vector<int> priority,
                Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 1) return Actions::XSpeed;
  return Actions::Attack;
}

Actions Misty(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
              Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 1) return Actions::XDefend;
  return Actions::Attack;
}

Actions SabrinaRB(std::vector<Move> moves, std::vector<int> priority,
                  Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  double percentageHP = user->getCurrentHP() / user->getStat("hp");
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && percentageHP < 0.1 && itemsUsed < 1)
    return Actions::HyperPotion;
  return Actions::Attack;
}

Actions SabrinaY(std::vector<Move> moves, std::vector<int> priority,
                 Pokemon* user, Pokemon* opponent, int seed) {
  int num = random(seed, 1, 100);
  int itemsUsed = user->getItemsUsed();
  if (num <= 25 && itemsUsed < 1) return Actions::XDefend;
  return Actions::Attack;
}