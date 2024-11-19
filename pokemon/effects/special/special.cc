#include "special.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Special::Special(const json& effects) {
  const json& status = effects["status"];
  this->userStatus = status.contains("user") ? status["user"] : Status();
  this->oppStatus = status.contains("target") ? status["target"] : Status();
}