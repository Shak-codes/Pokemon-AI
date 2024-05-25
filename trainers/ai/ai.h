#ifndef __AI__
#define __AI__

#include <string>
#include <vector>

#include "../constants/enums.h"
#include "../moves/move.h"
#include "../pokemon.h"

class AI {
 public:
  AI(TrainerClass t_class);
  int chooseMove(TrainerClass trainerClass, std::vector<Pokemon*>& team,
                 std::vector<Pokemon*>& oTeam);
};

#endif