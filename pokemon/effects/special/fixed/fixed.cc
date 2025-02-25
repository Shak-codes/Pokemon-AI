#include "fixed.h"

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

Fixed::Fixed(const json& effects) {
  if (effects.contains("fixed")) {
    const auto& fixedData = effects["fixed"];
    std::string type = fixedData.value("type", "");

    if (type == "opponentHealth") {
      variant = OPP_HP;
      value = fixedData.value("value", 0.0f);
    } else if (type == "level") {
      variant = USER_LEVEL;
      value = 0;
    } else if (type == "constant") {
      variant = CONSTANT;
      value = fixedData.value("value", 0.0f);
    }
    fixed = true;
  }
}

Fixed::DamageVariant Fixed::getVariant() { return variant; }

float Fixed::getValue() const { return value; }

bool Fixed::isFixed() const { return fixed; }
