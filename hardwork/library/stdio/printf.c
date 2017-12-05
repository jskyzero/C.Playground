#include <stdio.h>


void usage() {
  puts("\nfunction printf");
  puts("int printf (const char * format, ... );");
  puts("Write the C string pointed by format to the standard output");
  puts("\nformat");
  puts("%[flags][width][.preecision][length]specifier");
  puts("specifier	: d, i, u, o, x, f, e, g, a, c, s, p, n, %");
  puts("flags		: -, +, (space), #, 0");
  puts("width		: (number), *");
  puts("precision	: (.number), (.*)");
  puts("specifiers	: hh, h, l, ll, j, z, t, L");
}

void practice_basic() {
  unsigned num = 520;
  float num2 = 520.12;
 
  printf("signed decimal integer                       %d\n", (int)num);
  printf("unsigned decimal integer                     %u\n", num);
  printf("unsigned octal                               %o\n", num);
  printf("unsigned hexadecimal integer                 %x\n", num);
  printf("decimal float point                                   %f\n", num2);
  printf("scientific notation (mantissa/exponent), lowecase     %e\n", num2);
}

void practice_master() {
  float num = 520.1314;

  printf("|+%f|\n", num);
  printf("| %f|\n", num);
  printf("|%+20f|\n", num);
  printf("|% 20f|\n", num);
  printf("|%-20f|\n", num);
  printf("|%-*.*f|\n", 20, 2, num);
  printf("|%20.2f|\n", num);
}

void practice() {
  practice_basic();
  practice_master();
}

int main() {
  usage();
  practice();

  unsigned i = -1;
  printf("%u\t", i);

  return 0;
}
