#include <stdlib.h>

#include "clll.h"

struct Clll {
  struct Clll *next;
  struct Clll *prev;
  void *data;
  size_t len;
};


struct Clll *new_clll(){
  struct Clll *head = malloc(sizeof(struct Clll));
  if (head != NULL){
    head->next = head;
    head->prev = head;
    head->data = NULL;
    head->len = 0;
  }
  return head;
}


int push(struct Clll *head, void *data, size_t len){
  if (head->data == NULL){
    head->data = data;
    head->len = len;
    return 0;
  }
  struct Clll *new = malloc(sizeof(struct Clll));
  if (new !=NULL){
    new->next = head;
    new->prev = head->prev;
    new->data = data;
    new->len = len;

    head->prev->next = new;
    head->prev = new;

    return 0;
  }else{
    return -1;
  }
}

int pop(struct Clll *head, void **data, size_t *len){
  if (head->data == NULL){
    return -1;
  }
  *data = head->prev->data;
  *len = head->prev->len;

  if (head->next == head){
    head->data = NULL;
    head->len = 0;
  }else{
    if (head->next == head->prev){
      free(head->prev);
      head->prev = head;
      head->next = head;
    }else{
      struct Clll *to_free = head->prev;
      head->prev = head->prev->prev;
      head->prev->next = head;
      free(to_free);
    }
  }
  return 0;
}

int fpush(struct Clll **head, void *data, size_t len){
  if ((*head)->data == NULL){
    (*head)->data = data;
    (*head)->len = len;

    return 0;
  }
  struct Clll *new = malloc(sizeof(struct Clll));
  if (new == NULL){
    return -1;
  }
  new->next = *head;
  new->prev = (*head)->prev;
  new->data = data;
  new->len = len;

  (*head)->prev->next = new;
  (*head)->prev = new;

  *head = new;

  return 0;
}

int fpop(struct Clll **head, void **data, size_t *len){
  if((*head)->data == NULL){
    return -1;
  }
  *data = (*head)->data;
  *len = (*head)->len;

  if ((*head)->next == *head){
    (*head)->data = NULL;
    (*head)->len = 0;
  }else{
    struct Clll *to_free = *head;
    if ((*head)->next == (*head)->prev){
      *head = (*head)->next;
      (*head)->next = *head;
      (*head)->prev = *head;
    }else{
      *head = (*head)->next;
      (*head)->prev = (*head)->prev->prev;
      (*head)->prev->next = *head;
    }
    free(to_free);
  }
  return 0;
}


int isempty(struct Clll *head){
  return head->data == NULL;
}
