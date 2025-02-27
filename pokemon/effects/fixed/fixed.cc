#include "fixed.h"

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

Fixed::Fixed(const json& effects) {
  if (!effects.contains("fixed")) return;

  const auto& fixedData = effects["fixed"];
  std::string type = fixedData.value("type", "");

  if (type == "opponentHealth") {
    variant = DamageVariant::OPP_HP;
    value = fixedData.value("value", 0.0f);
  } else if (type == "level") {
    variant = DamageVariant::USER_LEVEL;
    value = 0;
  } else {
    variant = DamageVariant::CONSTANT;
    value = fixedData.value("value", 0.0f);
  }
}

Fixed::DamageVariant Fixed::getVariant() { return variant; }

float Fixed::getValue() const { return value; }

bool Fixed::hasEffect() const { return variant != DamageVariant::NONE; }
