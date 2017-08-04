#include <stdio.h> // for printf()
#include <stdlib.h> // for rand()
#include <time.h> // for time()

#define TEST_SIZE 10

typedef int num_type;

void dec_to_bin(num_type n);
void print_binary(num_type n);

int main() {
  // void srand (unsigned int seed)
  srand(time(NULL));

  for (int i = 0; i < TEST_SIZE; i++) {
    // int rand (void)
    // num_type == rand return value type
    dec_to_bin(rand());
  }
}

// print the dec and bin value of the num
void dec_to_bin(num_type n ) {
  printf("%22d(10) is ", n); 
  print_binary(n);
  printf("(2)\n");
}

void print_binary(num_type n) {
  if (n <= 0) return;
  print_binary(n / 2);
  printf("%d", n % 2);
}