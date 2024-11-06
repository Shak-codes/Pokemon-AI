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
  Type getType() const;
  std::string getName() const;
  int getDamage() const;
  int getPP() const;
  Effect getEffect() const;
  bool pureStatus() const;
  bool isBuff() const;
  bool isDebuff() const;
};

#endif