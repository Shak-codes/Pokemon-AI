#include "special.h"

#include <algorithm>
#include <string>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Special::Special(std::string move, const json& effects)
    : fixed(effects), multistrike(effects), recoil(effects) {
  std::string name = move;

  for (const auto& flags : allFlags) {
    if (std::find(flags.begin(), flags.end(), name) != flags.end()) {
      isSpecial = true;
      specialEffect = name;
      break;
    }
  }
}

bool Special::hasSpecialEffect() const { return isSpecial; }

std::string Special::getSpecialEffect() const {
  if (isSpecial) return specialEffect;
  return "N/A";
}
