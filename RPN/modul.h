#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct element
{
  int dana;
  struct element *nast;
} t_elem;

void push(t_elem **stos, int elem);
int pop(t_elem **stos);
int empty(t_elem **stos);
void print(t_elem **stos);
