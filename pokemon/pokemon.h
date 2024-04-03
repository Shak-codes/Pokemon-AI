#ifndef __POKEMON__
#define __POKEMON__

#include <iostream>
#include <string>
#include <vector>

#include "move.h"
#include "stats.h"

class Pokemon {
 private:
  std::string name;
  Stats stats;
  std::vector<Move> moves;

 public:
  Pokemon(std::string& name, Stats stats, std::vector<Move> moves);
  std::string getName();
  int getStat(std::string& stat);
  std::vector<Move> getMoves();
};

#endif