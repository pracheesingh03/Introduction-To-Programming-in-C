#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  card_t **card= (*hand).cards;
  for (int i=0;i<(*hand).n_cards;i++){
    print_card(**card);
    card++;
  }

}

int deck_contains(deck_t * d, card_t c) {
  card_t **card= (*d).cards;
  for(int i=0; i<(*d).n_cards; i++)
    {
      if((value_letter(**card)==c.value)&&(suit_letter(**card)==c.suit))
      return 1;
    card++;
    }
  return 0;
}

void shuffle(deck_t * d){
  card_t **card=(*d).cards;
  card_t *temp;
  for(size_t i=0; i<(*d).n_cards/2; i++)
    {
      int y =random()%(*d).n_cards;
      temp= card[i];
      card[i]= card[y];
      card[y]=temp;
    }
}

void assert_full_deck(deck_t * d) {
  card_t **card= (*d).cards;
  assert_card_valid(**card);
}
