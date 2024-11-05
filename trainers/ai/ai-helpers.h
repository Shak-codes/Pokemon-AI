#ifndef _AI_HELPERS_
#define _AI_HELPERS_

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
    if (move.pureStatus() && opponent->getStatus() != Status::NONE) {
      priority[idx] += 5;
    }
    idx++;
  }
}

void mod2(std::vector<Move> moves, std::vector<int> priority, Pokemon* user,
          Pokemon* opponent) {
  int idx = 0;
  for (auto& move : moves) {
    if (move.getEffect() != Effect::NONE) {
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

std::vector<Mod> getMods(TrainerClass trainerClass) {
  std::vector<Mod> modifications;
  if (trainerClass != TrainerClass::Youngster &&
      trainerClass != TrainerClass::CueBall) {
    modifications.push_back(mod1);
    std::cout << "Trainer " << TrainerClassNames[static_cast<int>(trainerClass)]
              << " has modification 1" << std::endl;
  }
  if (trainerClass == TrainerClass::Pokemaniac ||
      trainerClass == TrainerClass::SuperNerd ||
      trainerClass == TrainerClass::Juggler ||
      trainerClass == TrainerClass::Psychic ||
      trainerClass == TrainerClass::Scientist ||
      trainerClass == TrainerClass::Gentleman ||
      trainerClass == TrainerClass::Lorelei) {
    modifications.push_back(mod2);
    std::cout << "Trainer " << TrainerClassNames[static_cast<int>(trainerClass)]
              << " has modification 2" << std::endl;
  }
  if (trainerClass == TrainerClass::Sailor ||
      trainerClass == TrainerClass::Pokemaniac ||
      trainerClass == TrainerClass::Burglar ||
      trainerClass == TrainerClass::Fisher ||
      trainerClass == TrainerClass::Swimmer ||
      trainerClass == TrainerClass::Beauty ||
      trainerClass == TrainerClass::Rocker ||
      trainerClass == TrainerClass::Giovanni ||
      trainerClass == TrainerClass::CooltrainerM ||
      trainerClass == TrainerClass::CooltrainerF ||
      trainerClass == TrainerClass::Misty ||
      trainerClass == TrainerClass::Surge ||
      trainerClass == TrainerClass::Erika ||
      trainerClass == TrainerClass::Koga ||
      trainerClass == TrainerClass::Blaine ||
      trainerClass == TrainerClass::Sabrina ||
      trainerClass == TrainerClass::Rival2 ||
      trainerClass == TrainerClass::Rival3 ||
      trainerClass == TrainerClass::Lorelei ||
      trainerClass == TrainerClass::Lance) {
    modifications.push_back(mod3);
    std::cout << "Trainer " << TrainerClassNames[static_cast<int>(trainerClass)]
              << " has modification 3" << std::endl;
  }
  return modifications;
}

#endif