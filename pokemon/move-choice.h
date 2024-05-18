#ifndef _MOVE_CHOICE_
#define _MOVE_CHOICE_

#include "move.h"

class MoveChoice {
  int priority;
  Move move;

 public:
  MoveChoice(int priority, const Move& move);
  int getPriority();
  void changePriority(int priority);
  Move getMove();
};

#endif