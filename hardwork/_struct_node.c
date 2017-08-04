#include <stdio.h>

struct Node {
	int data;
	struct Node * next;
};

typedef struct Node Node;

/*
typedef struct Node {
    int date;
    struct Node *next;
  } LNode, *LinkList;  
*/
int main() {
  Node head = {0, NULL};
  printf("sizeof Node %ld\n", sizeof(Node));
  printf("sizeof Instance %ld\n", sizeof(head));
  printf("sizeof Instance data %ld\n", sizeof(head.data));
  printf("sizeof Instance next %ld\n", sizeof(head.next));

  return 0;
}
