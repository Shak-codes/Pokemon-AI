#ifndef __POKEMON__
#define __POKEMON__

#include <iostream>
#include <string>
#include <vector>

#include "constants/enums.h"
#include "move.h"
#include "stats.h"

class Pokemon {
 private:
  std::string name;
  Stats stats;
  std::vector<Move> moves;
  Status status = Status::NONE;
  std::vector<Type> types;

 public:
  Pokemon(std::string& name, Stats stats, std::vector<Move> moves);
  std::string getName() const;
  std::vector<Type> getTypes() const;
  int getStat(std::string& stat) const;
  std::vector<Move> getMoves() const;
  Status getStatus() const;
};

#endif