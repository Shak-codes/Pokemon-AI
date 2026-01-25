#ifndef __FIELD__
#define __FIELD__

#include <string>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

/*
  This class defines the structure for how the Field effect works.
  Field moves have different effects depending on the exact move.
  FIELD MOVES:
    Reflect
    Mist
    Lightscreen
*/
class Field {
 private:
  std::string type{""};
  bool isField{false};

 public:
  Field(const json& effects);
  bool hasEffect() const;
  const std::string& getFieldType() const;
};

#endif