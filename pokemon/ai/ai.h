#ifndef __AI__
#define __AI__

#include <string>
#include <vector>

#include "../constants/enums.h"
#include "../move.h"
#include "../pokemon.h"

class AI {
 public:
  int chooseMove(TrainerClass trainerClass, std::vector<Pokemon*>& team,
                 std::vector<Pokemon*>& oTeam);
};

#endif