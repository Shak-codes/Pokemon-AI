#include "ai.h"

#include <string>
#include <vector>

#include "../constants/enums.h"
#include "../move.h"
#include "../pokemon.h"
#include "ai-helpers.h"

int AI::chooseMove(TrainerClass trainerClass, std::vector<Pokemon*>& team,
                   std::vector<Pokemon*>& oTeam) {
  Pokemon* current = team[0];
  std::vector<std::function<void(std::vector<Move>, std::vector<int>, Pokemon*,
                                 Pokemon*)>>
      modifications = determineModifications(trainerClass);
  return 0;
};