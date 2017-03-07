#include <stdlib.h>

struct Clll;

struct Clll *new_clll();
int push(struct Clll *head, void *data, size_t len);
int pop(struct Clll* head, void **data, size_t *len);
int fpop(struct Clll **head, void **data, size_t *len);
int fpush(struct Clll **head, void *data, size_t len);
