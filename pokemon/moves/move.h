#ifndef __MOVE__
#define __MOVE__

#include <string>

#include "../constants/enums.h"

class Move {
  std::string name;
  Type type;
  Category category;
  Target target;
  int power;
  float accuracy;
  int pp;
  bool special;
  Effect effect;

 public:
  Move(const std::string& name, Type type, Category category, Target target,
       int power, float accuracy, int pp, bool special);
  std::string getName() const;
  Type getType() const;
  Category getCat() const;
  Target getTarget() const;
  int getPwr() const;
  float getAcc() const;
  int getPP() const;
  bool getSpecial() const;
  // Effect getEffect() const;
  // bool pureStatus() const;
  // bool isBuff() const;
  // bool isDebuff() const;
};

#endif