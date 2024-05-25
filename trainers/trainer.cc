// Trainer.cpp
#include "trainer.h"

#include <string>
#include <vector>

Trainer::Trainer(TrainerClass trainerClass, std::vector<Pokemon*> team)
    : trainerClass{trainerClass}, team{team} {}

int Trainer::battle(Trainer* opponent) {
  std::string winner;
  while (this->teamStatus() && opponent->teamStatus()) {
    int trainer1Move =
        this->ai.chooseMove(this->trainerClass, *&this->team, *&opponent->team);
    int trainer2Move = this->ai.chooseMove(opponent->trainerClass,
                                           *&opponent->team, *&this->team);
    break;
  }
  return 0;
};

bool Trainer::teamStatus() const { return true; }