#include "move-choice.h"

#include "move.h"

MoveChoice::MoveChoice(int priority, const Move& move)
    : priority{priority}, move{move} {}

void MoveChoice::changePriority(int priority) { this->priority = priority; }

Move MoveChoice::getMove() { return move; }

int MoveChoice::getPriority() { return priority; }