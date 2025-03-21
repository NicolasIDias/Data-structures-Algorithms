#include <stdio.h>

int main()
{

  int k, r;

  int counter = 1;

  scanf("%d %d", &k, &r);

  int price = k;

  while ((price % 10 != r) && (price % 10 != 0))
  {
    counter++;
    price += k;
  }

  printf("%d", counter);

  return 0;
}