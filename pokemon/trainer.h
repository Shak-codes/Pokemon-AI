#ifndef __TRAINER__
#define __TRAINER__

#include <string>
#include <vector>

#include "ai/ai.h"
#include "constants/enums.h"
#include "pokemon.h"

class Trainer {
  TrainerClass trainerClass;
  std::vector<Pokemon*> team;
  Pokemon* activePokemon;
  AI ai;

 public:
  Trainer(TrainerClass trainerClass, std::vector<Pokemon*> team);
  int battle(Trainer* opponent);
  bool teamStatus() const;
};

#endif