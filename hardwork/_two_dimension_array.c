#include <stdio.h> // for printf()
#include <assert.h> // for assert()


typedef int(*Array_Type)[4];

void print_two_dimension_array(int(*array)[4], int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf("%p-%ld\n", array[i], sizeof(array[i]));
  }
  printf("\n");
}

void print_two_dimension_pointer(int **array, int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf("%p-%ld\n", array[i], sizeof(array[i]));
  }
  printf("\n");
}

int main() {
  int a[3][4] = {{1, 2}, {3, 4}, {5, 6, 7}};
  print_two_dimension_array(a, 3);
  print_two_dimension_pointer(a, 3);
  // this means a[m][n] == *(*(a + m) + n)
  // assert(a[0][1] == *(*(a + 0) + 1));
  printf("&a       = %p\n", &a);
  printf("a        = %p\n", a);
  printf("a[0]     = %p\n", a[0]);
  printf("&a[0][0] = %p\n", &a[0][0]);
  printf("&a[0][1] = %p\n", &a[0][1]);
  printf("&a[0][2] = %p\n", &a[0][2]);
  printf("a + 1    = %p\n", a + 1);
  printf("a[1]     = %p\n", a[1]);
  printf("&a[1][0] = %p\n", &a[1][0]);
}


