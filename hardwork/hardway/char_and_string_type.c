#include <stdio.h>   // for scanf() printf()
#include <assert.h>  // for assert()

typedef char char_type1;
typedef char *char_type2;
typedef char(char_type3);
typedef char(*char_type4);
typedef char *(char_type5);

typedef char(str_type1)[2];
typedef char (*str_type2)[2];

int main() {
  char_type1 ch1 = 'A';
  char_type2 ch2 = &ch1;
  assert(*ch2 = ch1);

  char_type3 ch3 = ch1;
  assert(ch3 = ch1);

  char_type4 ch4 = ch2;
  assert(*ch4 = ch3);

  char_type5 ch5 = ch4;
  assert(*ch5 == ch1);

  str_type1 str1 = "A";
  assert(str1[0] == 'A');
  assert(str1[1] == '\0');

  char_type2 str0 = str1;
  assert(str0[0] == 'A');
  assert(str0[1] == '\0');

  str_type2 str2 = &str1;
  assert(str2[0][0] == 'A');
  assert(str2[0][1] == '\0');

  return 0;
}
