#include "fixed.h"

#include "../../../../lib/json.hpp"

using json = nlohmann::json;

Fixed::Fixed(const json& damage) {
  if (damage.contains("fixed")) {
    const auto& fixedData = damage["fixed"];
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
  }
}

Fixed::DamageVariant Fixed::getVariant() { return variant; }

float Fixed::getValue() const { return value; }
