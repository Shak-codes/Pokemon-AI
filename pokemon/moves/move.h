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
  Effect effect;

 public:
  Move(const std::string& name, Type type, Category category, Target target,
       int power, float accuracy, int pp);
  std::string getName() const;
  Type getType() const;
  Category getCat() const;
  Target getTarget() const;
  int getPwr() const;
  float getAcc() const;
  int getPP() const;
  // Effect getEffect() const;
  // bool pureStatus() const;
  // bool isBuff() const;
  // bool isDebuff() const;
};

#endif