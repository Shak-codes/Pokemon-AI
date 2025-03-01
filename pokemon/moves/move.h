#ifndef __MOVE__
#define __MOVE__

#include <string>

#include "../constants/enums.h"
#include "../../lib/json.hpp"

class Move {
  std::string name;
  Type type;
  Category category;
  int power;
  float accuracy;
  int maxPP;
  int pp;
  bool special;
  Effect effects;

 public:
  Move(const json& moveData);
  std::string getName() const;
  Type getType() const;
  Category getCategory() const;
  int getPower() const;
  float getAccuracy() const;
  int getPP() const;
  void decrementPP();
  void restorePP(int value);
  Effect getEffect() const;
};

#endif