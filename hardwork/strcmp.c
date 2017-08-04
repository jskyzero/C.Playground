#include <stdio.h> // for scanf() printf()
#include <string.h> // fot strcmp()

char s0[30], c0[30];
int main() {
  char a[49][2][30] = {{"Alabama", "Montgomery"},
                       {"Alaska", "Juneau"},
                       {"Arizona", "Phoenix"},
                       {"Arkansas", "Little Rock"},
                       {"California", "Sacramento"},
                       {"Colorado", "Denver"},
                       {"Connecticut", "Hartford"},
                       {"Delaware", "Dover"},
                       {"Florida", "Tallahassee"},
                       {"Georgia", "Atlanta"},
                       {"Hawaii", "Honolulu"},
                       {"Idaho", "Boise"},
                       {"Illinois", "Springfield"},
                       {"Maryland", "Annapolis"},
                       {"Minnesota", "Saint Paul"},
                       {"Iowa", "Des Moines"},
                       {"Maine", "Augusta"},
                       {"Kentucky", "Frankfort"},
                       {"Indiana", "Indianapolis"},
                       {"Kansas", "Topeka"},
                       {"Louisiana", "Baton Rouge"},
                       {"Oregon", "Salem"},
                       {"Oklahoma", "Oklahoma City"},
                       {"Ohio", "Columbus"},
                       {"North Dakota", "Bismark"},
                       {"New York", "Albany"},
                       {"New Mexico", "Santa Fe"},
                       {"New Jersey", "Trenton"},
                       {"New Hampshire", "Concord"},
                       {"Nevada", "Carson City"},
                       {"Nebraska", "Lincoln"},
                       {"Montana", "Helena"},
                       {"Missouri", "Jefferson City"},
                       {"Mississippi", "Jackson"},
                       {"Massachusettes", "Boston"},
                       {"Michigan", "Lansing"},
                       {"Pennslyvania", "Harrisburg"},
                       {"Rhode Island", "Providence"},
                       {"South Carolina", "Columbia"},
                       {"South Dakota", "Pierre"},
                       {"Tennessee", "Nashville"},
                       {"Texas", "Austin"},
                       {"Utah", "Salt Lake City"},
                       {"Vermont", "Montpelier"},
                       {"Virginia", "Richmond"},
                       {"Washington", "Olympia"},
                       {"West Virginia", "Charleston"},
                       {"Wisconsin", "Madison"},
                       {"Wyoming", "Cheyenne"}};
  int n = 0;
  int N = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s0);
    scanf("%s", c0);
    for (int j = 1; j < 49; j++) {
      if (0 == strcmp(s0, a[j][0])) {
        N = j;
        break;
      }
    }
    if (0 == strcmp(c0, a[N][1]))
      printf("Your anwswer is correct\n");
    else
      printf("The capital of %s is %s\n", a[N][0], a[N][1]);
  }
  return 0;
}
