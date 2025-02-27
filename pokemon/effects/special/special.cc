#include "special.h"

#include <algorithm>
#include <string>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Special::Special(const json& effects) {
  if (!effects.contains("special")) return;
  name = effects["special"];
}

bool Special::hasEffect() const { return name != "N/A"; }

std::string Special::getSpecialEffect() const { return name; }
