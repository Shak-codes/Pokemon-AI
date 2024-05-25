#ifndef __MOVE__
#define __MOVE__

#include <string>

#include "../constants/enums.h"

class Move {
  Effect effect;
  Type type;
  std::string name;
  int dmg;
  int pp;

 public:
  Move(const std::string& name, Type type, int dmg, int pp, Effect effect);
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