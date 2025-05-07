#ifndef __FIELD__
#define __FIELD__

#include <string>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class Field {
 private:
  std::string type{""};
  bool isField{false};

 public:
  Field(const json& effects);
  bool hasEffect() const;
};

#endif