#include <string.h>
#include <stdio.h>

int *doubleCapacity(int *list, int size) {
  size *= 2;
  // int *items;
  int *newItems = new int[size];
  memcpy(newItems, list, sizeof(int) * size);
  delete[] list;
  list = newItems;
  return list;
}

int main() {
  int list[5] = {1, 2, 3, 4, 5};
  int *newlist = doubleCapacity(list, 5);
  for (int i = 0; i < 2 * 5; i++) printf("%d ", *(newlist + i));
}
