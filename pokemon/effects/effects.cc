#include "effects.h"

#include <string>

#include "../../lib/json.hpp"
#include "status/status.h"

using json = nlohmann::json;

Effects::Effects(const json& effects) {
  const json& status = effects["status"];
  this->userStatus =
      status.contains("user") ? Status(status["user"]) : Status();
  this->oppStatus =
      status.contains("target") ? Status(status["opponent"]) : Status();
};