// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

#ifndef ITEM_H
position_t get_item_position(Item item);
#endif

struct _defender_spy {
  Item item;
  size_t number_uses;
};

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_pos, Spy attacker_spy) {
  struct _defender_spy *spy = (struct _defender_spy*) attacker_spy;
  position_t attacker_pos = get_item_position(spy->item);
  direction_t ans = DIR_STAY;
  
  if (attacker_pos.i > defender_pos.i) {
    ans.i = 1;
  } else if (attacker_pos.i < defender_pos.i) {
    ans.i = -1;
  }

  if (attacker_pos.j > defender_pos.j) {
    ans.j = 1;
  } else if (attacker_pos.j < defender_pos.j) {
    ans.j = -1;
  }

  return ans;
}

/*----------------------------------------------------------------------------*/
