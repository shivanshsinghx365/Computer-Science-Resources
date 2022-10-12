#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int top;
  int *v;
}stack;

int full (stack* p) {
  return p->top == p->size;
}

int empty (stack* p) {
  return p->top == 0;
}

//Create a new stack with size N
stack* newStack(int N) {
  stack* p = (stack*)malloc(sizeof(stack));
  p->v = (int *)malloc(N * sizeof(int));
  p->size = N;
  p->top = 0;

  return p;
} 

void push(stack* p, int x) {
  if(full(p)) {
    printf("stack overflow\n");
    exit(1);
  }

  p->v[p->top] = x;
  p->top++;
}

int pop(stack* p) {
  if(empty(p)) {
    printf("stack underflow\n");
    exit(1);
  }
  p->top--;
  return (p->v[p->top]);
}


int main(void) {

  stack* a = newStack(10);
  push(a, 6);
  push(a, 10);
  push(a, -12);
  printf("\n stack top %d", a->v[a->top-1]);

  int z = pop(a);
  printf("\n pop %d / new top %d",z, a->v[a->top-1]);
  

  return 0;
}