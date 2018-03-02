#include <stdio.h>
#include <string.h>

int main() {
  int array[] = {1, 2, 3};
  int target[3];

  memset(target, 0, sizeof(int) * 3);
  puts("initial array");
  for (int i = 0; i < 3; i++) {
    printf("index: %d value: %d\n", i, target[i]);
  }


  memcpy(target, array, sizeof(int) * 3);
  puts("after copy array");
  for (int i = 0; i < 3; i++) {
    printf("index: %d value: %d\n", i, target[i]);
  }
  return 0;
}