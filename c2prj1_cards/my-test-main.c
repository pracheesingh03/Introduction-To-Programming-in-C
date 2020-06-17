#include "cards.h"
void assert_card_valid(card_t c);
int main(void) {
  card_t c;
  c.value= 1;
  c.suit= SPADES;
  assert_card_valid(c);
}
