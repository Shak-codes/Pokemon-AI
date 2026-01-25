#ifndef __STATUS__
#define __STATUS__

#include <map>
#include <string>
#include <vector>

#include "../../../lib/json.hpp"
using json = nlohmann::json;

/**
 * Status class for move effects.
 *
 * This class stores the status effects that a move can apply to either
 * the user or the opponent. Each status effect has an associated chance
 * (0.0 to 1.0) of being applied when the move is used (given the move hits).
 *
 * Example JSON format:
 * "status": {
 *   "opponent": {
 *     "paralyze": 0.301  // 77/256 chance (~30.1%) to paralyze
 *   }
 * }
 *
 * NON-VOLATILE STATUS CONDITIONS (Gen 1):
 * These persist after battle and switching out. A Pokemon can only have ONE
 * non-volatile status at a time.
 *
 * - burn: 1/16 max HP damage per turn, Attack reduced to 50%
 *         Fire-types are immune. Cured by Burn Heal, Full Heal, Rest, Haze.
 *
 * - freeze: Pokemon cannot act. No natural thaw in Gen 1!
 *           Cured by Ice Heal, Full Heal, Haze, or being hit by a
 *           burn-inducing Fire move (not Fire Spin).
 *           Ice-types are immune.
 *
 * - paralyze: Speed reduced to 25%, 25% chance to be fully paralyzed each turn.
 *             Cured by Parlyz Heal, Full Heal, Rest, Haze.
 *             Pokemon cannot be paralyzed by moves of their own type.
 *
 * - poison: 1/16 max HP damage per turn.
 *           Poison-types are immune. Cured by Antidote, Full Heal, Rest, Haze.
 *
 * - badly-poisoned: Inflicted by Toxic. Damage increases each turn (N/16 max HP
 *                   where N starts at 1 and increments each turn).
 *                   Reverts to regular poison when switching out or after battle.
 *                   Still counts as "poison" status - Pokemon can't have both.
 *                   Poison-types are immune. Same cures as regular poison.
 *                   Gen 1 bug: If cured by Rest then burned, burn damage uses
 *                   the bad poison counter and continues incrementing.
 *
 * - sleep: Pokemon cannot act for 1-7 turns (counter decrements on move attempt).
 *          Rest always lasts exactly 2 turns (3 turns total to act again).
 *          Cured by Awakening, Full Heal, Poke Flute, Haze, or counter reaching 0.
 *
 * VOLATILE STATUS CONDITIONS (tracked separately during battle):
 * - confusion: 50% chance to hurt self, lasts 1-4 turns
 * - flinch, bound, seeded, etc.
 *
 * Note: Confusion is volatile but stored here for convenience since it acts
 * similarly to a status effect.
 */
class Status {
 private:
  std::map<std::string, float> statusEffects{};

 public:
  Status(const json& effects);

  /**
   * Get the full map of status effects and their chances.
   * @return Map of status effect name to application chance
   */
  std::map<std::string, float> getStatusEffect() const;

  /**
   * Check if this status effect has any effects.
   * @return true if at least one status effect is defined
   */
  bool hasEffect() const;

  /**
   * Get the chance for a specific status effect.
   * @param status The status effect name (e.g., "paralysis", "burn")
   * @return The chance (0.0 to 1.0) or 0.0 if not found
   */
  float getChance(const std::string& status) const;

  /**
   * Get all status effect types that this move can apply.
   * @return Vector of status effect names
   */
  std::vector<std::string> getStatuses() const;
};

#endif
