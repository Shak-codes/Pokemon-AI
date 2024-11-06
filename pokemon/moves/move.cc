// Move.cpp
#include "move.h"

#include "../constants/enums.h"

Move::Move(const std::string& name, Type type, Category category, Target target,
           int power, float accuracy, int pp)
    : name(name),
      type(type),
      category(category),
      target(target),
      power(power),
      accuracy(accuracy),
      pp(pp) {}

std::string Move::getName() const { return name; }

Type Move::getType() const { return type; }

int Move::getDamage() const { return power; }

int Move::getPP() const { return pp; }

Effect Move::getEffect() const { return effect; }

bool Move::pureStatus() const { return effect == Effect::STATUS && power == 0; }

bool Move::isBuff() const { return effect == Effect::BUFF; }

bool Move::isDebuff() const { return effect == Effect::DEBUFF; }