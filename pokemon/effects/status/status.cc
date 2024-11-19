#include "status.h"

#include "../../../lib/json.hpp"

using json = nlohmann::json;

Status::Status(const json& status) {
  this->burn = status.value("burn", 0.0f);
  this->freeze = status.value("freeze", 0.0f);
  this->paralysis = status.value("paralysis", 0.0f);
  this->poison = status.value("poison", 0.0f);
  this->badlyPoisoned = status.value("badlyPoisoned", 0.0f);
  this->sleep = status.value("sleep", 0.0f);

  this->active =
      (this->burn > 0.0f || this->freeze > 0.0f || this->paralysis > 0.0f ||
       this->poison > 0.0f || this->badlyPoisoned > 0.0f || this->sleep > 0.0f);
}

bool Status::isActive() const { return active; }
float Status::getBurn() const { return burn; }
float Status::getFreeze() const { return freeze; }
float Status::getParalysis() const { return paralysis; }
float Status::getPoison() const { return poison; }
float Status::getBadlyPoisoned() const { return badlyPoisoned; }
float Status::getSleep() const { return sleep; }

void Status::setActive(bool active) { this->active = active; }
void Status::setBurn(float value) { burn = value; }
void Status::setFreeze(float value) { freeze = value; }
void Status::setParalysis(float value) { paralysis = value; }
void Status::setPoison(float value) { poison = value; }
void Status::setBadlyPoisoned(float value) { badlyPoisoned = value; }
void Status::setSleep(float value) { sleep = value; }
