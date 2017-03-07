#include <stdio.h>

#include "clll.h"

int main(void){
  struct Clll *head = new_clll();
  char str1[] = "Salut";
  char str2[] = "Hello";
  char str3[] = "Bonjour";
  push(head, str1, sizeof(str1));
  push(head, str2, sizeof(str2));
  void *popped;
  size_t len;
  int status;
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  push(head, str3, sizeof(str3));
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = fpush(&head, str2, sizeof(str2));
  printf("%d\n", status);
  status = fpush(&head, str1, sizeof(str1));
  printf("%d\n", status);
  status = fpop(&head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = fpop(&head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = fpush(&head, str2, sizeof(str2));
  printf("%d\n", status);
  status = fpush(&head, str1, sizeof(str1));
  printf("%d\n", status);
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
  status = pop(head, &popped, &len);
  printf("%d: %s - %lu\n", status, (char *) popped, len);
}
