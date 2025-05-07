#ifndef __POKEMON__
#define __POKEMON__

#include <iostream>
#include <string>
#include <vector>

#include "../lib/json.hpp"
#include "constants/enums.h"
#include "moves/move.h"
#include "stats/stats.h"

using json = nlohmann::json;

class Pokemon {
 private:
  std::string name;
  std::vector<Type> types;
  int currentHP;
  Stats stats;
  std::vector<Move> moves;
  Status status = Status::None;

 public:
  Pokemon(const json& pokemon);
  std::string getName() const;
  std::vector<Type> getTypes() const;
  int getStat(std::string& stat) const;
  std::vector<Move> getMoves() const;
  Status getStatus() const;
  void reset();
};

#endif