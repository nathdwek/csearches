#include <stdio.h>

#include "clll.h"

int main(void){
  char buf1[] = "salut";
  char buf2[] = "coucou";
  char buf3[] = "bonjour";
  char buf4[] = "hello";
  struct Clll * head = new_clll();
  print_clll(head);
  push(head, buf1);
  print_clll(head);
  push(head, buf4);
  print_clll(head);
  fpush(&head, buf3);
  print_clll(head);
  fpush(&head, buf2);
  print_clll(head);
  pop(head);
  print_clll(head);
  fpop(&head);
  print_clll(head);
}
