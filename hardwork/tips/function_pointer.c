#include <stdio.h>
#include <stdlib.h>

int int_cmp(void const *left, void const *right) {
  return (*(int const *)left) - (*(int const *)right);
}

void int_swap(int *const left, int *const right) {
  if (*left != *right) {
    *left = *left + *right;
    *right = *left - *right;
    *left = *left - *right;
  }
}

void int_qsort(int *begin, int *end,
               int (*cmp_func)(void const *, void const *)) {
  int private = *begin;
  int i = 0;
  int j = (end - begin) - 1;

  while (i <= j) {
    while ((*cmp_func)(begin + i, &private) < 0) i++;
    while ((*cmp_func)(begin + j, &private) > 0) j--;
    if (i <= j) {
      int_swap(begin + i, begin + j);
      i++;
      j--;
    }
  }
  if (begin < begin + j) int_qsort(begin, begin + j + 1, cmp_func);
  if (begin + i < end - 1) int_qsort(begin + i, end, cmp_func);
}

int main() {
  int array[] = {4, 6, 7, 2, 1, 5, 3};
  int_qsort(array, array + 7, int_cmp);

  for (int i = 0; i < 7; i++) printf("index: %d value: %d\n", i, array[i]);

  return 0;
}