#include "fixed.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Fixed::Fixed(const json& effects) {
  if (!effects.contains("fixed")) return;

  const auto& fixedData = effects["fixed"];
  std::string type = fixedData.value("type", "");
  float parsedValue = fixedData.value("value", fixedData.value("damage", 0.0f));

  if (type == "opponentHealth" || type == "percentage") {
    variant = DamageVariant::OPP_HP;
    value = parsedValue;
  } else if (type == "level") {
    variant = DamageVariant::USER_LEVEL;
    value = 0;
  } else {
    variant = DamageVariant::CONSTANT;
    value = parsedValue;
  }
}

Fixed::DamageVariant Fixed::getVariant() const { return variant; }

float Fixed::getValue() const { return value; }

bool Fixed::hasEffect() const { return variant != DamageVariant::NONE; }

int Fixed::calculateDamage(int userLevel, int opponentCurrentHP) const {
  if (!hasEffect()) return 0;

  if (variant == DamageVariant::USER_LEVEL) {
    return userLevel < 0 ? 0 : userLevel;
  }

  if (variant == DamageVariant::OPP_HP) {
    if (opponentCurrentHP <= 0) return 0;
    float rawDamage =
        static_cast<float>(opponentCurrentHP) * value;
    int damage = static_cast<int>(std::floor(rawDamage));
    return damage < 0 ? 0 : damage;
  }

  int damage = static_cast<int>(std::floor(value));
  return damage < 0 ? 0 : damage;
}
