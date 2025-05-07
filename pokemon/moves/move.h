#ifndef __MOVE__
#define __MOVE__

#include <string>

#include "../../lib/json.hpp"
#include "../constants/enums.h"
#include "../effects/effects.h"

class Move {
  std::string name;
  Type type;
  Category category;
  Effects effects;
  int power;
  float accuracy;
  int maxPP;
  int pp;
  bool special;

 public:
  Move(const json& moveData);
  std::string getName() const;
  Type getType() const;
  Category getCategory() const;
  Effects getEffects() const;
  int getPower() const;
  float getAccuracy() const;
  int getPP() const;
  void decrementPP();
  void restorePP(int value);
  bool status() const;
};

#endif