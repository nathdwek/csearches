#include <stdlib.h>
#include <sodium.h>

#include "clll.h"

struct Bintree {
  int key;
  void *data;
  size_t len;
  struct Bintree *left;
  struct Bintree *right;
};


struct Bintree *gen_bintree(unsigned int max_depth){
  struct Bintree *new = malloc(sizeof(struct Bintree));
  if (new != NULL){
    new->key = randombytes_random();
    new->len = randombytes_uniform(64);
    new->data = malloc(new->len);
    if (new->data != NULL){
      randombytes_buf(new->data, new->len);
      if (max_depth){
        new->left = gen_bintree(max_depth - 1);
      }else{
        new->left = NULL;
      }
      if (max_depth){
        new->right = gen_bintree(max_depth - 1);
      }else{
        new->right = NULL;
      }
    }else{
      new = NULL;
    }
  }
  return new;
}


struct BintreeCtx{
  struct Bintree *bt;
  unsigned int nested_lvl;
};

struct BintreeCtx * new_bintree_ctx(struct Bintree *bt, unsigned int nested_lvl){
  struct BintreeCtx *new = malloc(sizeof(struct BintreeCtx));
  if (new != NULL){
    new->bt = bt;
    new->nested_lvl = nested_lvl;
  }
  return new;
}

void print_bintree(struct Bintree *bt){
  struct Clll *stack = new_clll();
  struct BintreeCtx *root, *current, *l, *r;

  root = new_bintree_ctx(bt, 0);
  push(stack, root);

  while (!isempty(stack)){
    current = fpop(&stack);
    for (unsigned int i = 0; i<current->nested_lvl; i++){
      printf("\t");
    }
    printf("%u\n", current->bt->key);
    if (current->bt->left != NULL){
      l = new_bintree_ctx(current->bt->left, current->nested_lvl+1);
      push(stack, l);
    }
    if (current->bt->right != NULL){
      r = new_bintree_ctx(current->bt->right, current->nested_lvl+1);
      push(stack, r);
    }
    free(current);
  }
}
