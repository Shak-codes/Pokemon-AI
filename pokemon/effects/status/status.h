#ifndef STATUS
#define STATUS

#include "../../../lib/json.hpp"

using json = nlohmann::json;

class Status {
 private:
  bool active = false;
  float burn = 0;
  float freeze = 0;
  float paralysis = 0;
  float poison = 0;
  float badlyPoisoned = 0;
  float sleep = 0;

 public:
  Status() = default;
  Status(const json& status);

  bool isActive() const;
  float getBurn() const;
  float getFreeze() const;
  float getParalysis() const;
  float getPoison() const;
  float getBadlyPoisoned() const;
  float getSleep() const;

  void setActive(bool active);
  void setBurn(float value);
  void setFreeze(float value);
  void setParalysis(float value);
  void setPoison(float value);
  void setBadlyPoisoned(float value);
  void setSleep(float value);
};

#endif
