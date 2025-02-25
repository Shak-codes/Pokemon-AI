#include "special.h"

#include <algorithm>
#include <string>

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Special::Special(const json& moveData)
    : fixed(moveData["effects"]),
      multistrike(moveData["effects"]),
      recoil(moveData["effects"]) {
  std::string name = moveData["name"];

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
