// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

#ifndef ITEM_H
position_t get_item_position(Item item);
#endif

struct _attack_spy {
  Item item;
  size_t number_uses;
};

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_pos, Spy defender_spy) {
  struct _attack_spy *spy = (struct _attack_spy*) defender_spy;
  position_t defender_pos = get_item_position(spy->item);
  direction_t ans = DIR_RIGHT;
  
  int delta = attacker_pos.i - defender_pos.i;
  if (delta < 0) delta *= -1;
  if (delta < 2) {
    ans.i = 1;
  }

  return ans;
}

/*----------------------------------------------------------------------------*/
