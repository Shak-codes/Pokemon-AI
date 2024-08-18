#include <cassert>
#include <string>

#include "../pokemon/constants/enums.h"
#include "../pokemon/moves/move.h"

int main() {
  Effect no_effect = Effect::NONE;
  Effect buff = Effect::BUFF;
  Effect debuff = Effect::DEBUFF;
  Effect status = Effect::STATUS;
  Type normal = Type::Normal;
  Move normal_move = Move("Normal Move", normal, 60, 20, no_effect);
  Move buff_move = Move("Buff Move", normal, 60, 20, buff);
  Move debuff_move = Move("Debuff Move", normal, 60, 20, debuff);
  Move status_move = Move("Status Move", normal, 60, 20, status);
  Move pure_status_move = Move("Normal Move", normal, 0, 20, status);

  assert(normal_move.getName() == "Normal Move" && ("Success! (name)"));
  assert(normal_move.getType() == normal && ("Success! (type)"));
  assert(normal_move.getDamage() == 60 && ("Success! (damage)"));
  assert(normal_move.getPP() == 20 && ("Success! (pp)"));
  assert(normal_move.getEffect() == Effect::NONE && ("Success! (no effect)"));
  assert(buff_move.getEffect() == Effect::BUFF && ("Success! (buff)"));
  assert(debuff_move.getEffect() == Effect::DEBUFF && ("Success! (debuff)"));
  assert(status_move.getEffect() == Effect::STATUS && ("Success! (status)"));
  assert(status_move.pureStatus() == false && ("Success! (non pure-status)"));
  assert(pure_status_move.pureStatus() == true && ("Success! (pure-status)"));

  return 0;
}