#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h> 
#include <assert.h>  
#include "pair.h"    /* TAD Par         */


pair_t pair_new(int x, int y) {
 pair_t k;
 k.fst = x;
 k.snd = y;
 
 assert(k.fst == x && k.snd == y);
 
 return k;
}
/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

int pair_first(pair_t p) {
  int k = p.fst;
  assert(k == p.fst);
  return k;
}
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

int pair_second(pair_t p) {
 int k = p.snd;
 assert(k == p.snd);
 return k; 
} 
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p) {
 pair_t k = {p.snd, p.fst};
 assert (k.fst == p.snd && k.snd == p.fst);
 return k;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p)}
 *
 */

pair_t pair_destroy(pair_t p) {
 return p; // no pedimos memoria, por lo tanto no destruimos nada.
}
