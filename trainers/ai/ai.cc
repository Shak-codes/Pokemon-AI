#include "ai.h"

#include <string>
#include <vector>

#include "../constants/enums.h"
#include "../moves/move.h"
#include "../pokemon.h"
#include "ai-helpers.h"

using Mod = std::function<void(std::vector<Move>, std::vector<int>, Pokemon*,
                               Pokemon*)>;

AI::AI(TrainerClass t_class) { std::vector<Mod> mods = getMods(t_class); }

int AI::chooseMove(TrainerClass trainerClass, std::vector<Pokemon*>& team,
                   std::vector<Pokemon*>& oTeam) {
  Pokemon* current = team[0];
  return 0;
};