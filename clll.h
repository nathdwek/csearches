#include <stdlib.h>

struct Clll;

struct Clll *new_clll();
int push(struct Clll *head, void *data);
void * pop(struct Clll* head);
void * fpop(struct Clll **head);
int fpush(struct Clll **head, void *data);
int isempty(struct Clll *head);
