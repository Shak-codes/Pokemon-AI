#include "field.h";

Field::Field(const json& effects) {
  if (!effects.contains("field")) return;

  const auto& fieldData = effects["fixed"];
  type = fieldData;
  isField = true;
}

bool Field::hasEffect() const { return isField; }