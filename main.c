#include <stdio.h>

#include "bintree.h"

int main(void){
  struct Bintree * bt = gen_bintree(5);
  print_bintree(bt);
  return 0;
}
