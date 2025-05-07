#ifndef __SPECIAL__
#define __SPECIAL__

#include <string>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

class Special {
 private:
  std::string name{"N/A"};

 public:
  Special(const json& effects);
  std::string getSpecialEffect() const;
  bool hasEffect() const;
};

#endif