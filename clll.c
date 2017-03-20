#include <stdlib.h>

#include "clll.h"

struct Clll {
  struct Clll *next;
  struct Clll *prev;
  void *data;
};


struct Clll *new_clll(){
  struct Clll *head = malloc(sizeof(struct Clll));
  if (head != NULL){
    head->next = head;
    head->prev = head;
    head->data = NULL;
  }
  return head;
}


int push(struct Clll *head, void *data){
  if (head->data == NULL){
    head->data = data;
    return 0;
  }
  struct Clll *new = malloc(sizeof(struct Clll));
  if (new !=NULL){
    new->next = head;
    new->prev = head->prev;
    new->data = data;

    head->prev->next = new;
    head->prev = new;

    return 0;
  }else{
    return -1;
  }
}

void * pop(struct Clll *head){
  if (head->data == NULL){
    return NULL;
  }
  void * data = head->prev->data;

  if (head->next == head){
    head->data = NULL;
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
  return data;
}

int fpush(struct Clll **head, void *data){
  if ((*head)->data == NULL){
    (*head)->data = data;

    return 0;
  }
  struct Clll *new = malloc(sizeof(struct Clll));
  if (new == NULL){
    return -1;
  }
  new->next = *head;
  new->prev = (*head)->prev;
  new->data = data;

  (*head)->prev->next = new;
  (*head)->prev = new;

  *head = new;

  return 0;
}

void * fpop(struct Clll **head){
  if((*head)->data == NULL){
    return NULL;
  }
  void * data = (*head)->data;

  if ((*head)->next == *head){
    (*head)->data = NULL;
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
  return data;
}


int isempty(struct Clll *head){
  return head->data == NULL;
}
