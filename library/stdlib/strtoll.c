#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtoll */

int main ()
{
  char szNumbers[] = "1856892505 17b00a12b -01100011010110000010001101100 0x6fffff 19";
  char* pEnd;
  long long int lli1, lli2, lli3, lli4, lli5;
  lli1 = strtoll (szNumbers, &pEnd, 10);
  printf("|%c|", pEnd[0]);
  lli2 = strtoll (pEnd, &pEnd, 16);
  lli3 = strtoll (pEnd, &pEnd, 2);
  lli4 = strtoll (pEnd, &pEnd, 0);
  lli5 = strtoll (pEnd, &pEnd, 8);
  printf("|%10s|", pEnd);
  printf ("The decimal equivalents are: %lld, %lld, %lld and %lld.\n", lli1, lli2, lli3, lli4);
  return 0;
}
