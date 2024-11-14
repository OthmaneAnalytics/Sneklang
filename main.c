#include <stdio.h>
#include "exercise.h"
#include <stdint.h>

typedef struct CoffeShop {
  int quality;
  int taste;
  int branding;
} coffee_shop_t;

int main() {
  int i1 = 1234;
  int i2 = 5678;

  swap(&i1, &i2, sizeof(int));
  printf("1234 %d\n5678 %d\n",i1,i2);
  char *s1 = "dax";
  char *s2 = "adam";

  swap(&s1, &s2, sizeof(char *));

  printf("dax %s\nadam %s\n",s1,s2);

  coffee_shop_t sbucks = {2, 3, 4};
  coffee_shop_t terminalshop = {10, 10, 10};

  swap(&sbucks, &terminalshop, sizeof(coffee_shop_t));

  printf("2 %d\n10 %d\n",sbucks.quality,terminalshop.quality);


  return 0;
}

