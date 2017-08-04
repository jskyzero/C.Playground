#include <stdio.h>   // for scanf() printf()
#include <stdlib.h>  // for malloc()

struct list {
  int num;
  struct list *next;
};
typedef struct list list;

int main() {
  int x;
  list *L, *p;
  L = (list *)malloc(sizeof(list));
  L->next = NULL;
  while (scanf("%d", &x) != EOF) {
    p = (list *)malloc(sizeof(list));
    p->num = x;
    p->next = L->next;
    L->next = p;
  }
  
  p = L->next;
  while (p != NULL) {
    printf("%d\n", p->num);
    p = p->next;
  }
}
