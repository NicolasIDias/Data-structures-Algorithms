#include <stdio.h>

int heavy_loop(int n)
{
  volatile unsigned long acc = 0;
  while (1)
  {
    for (int i = 0; i < 1000000; i++)
    {
      acc += i;
    }
    n++;
  }
  return n;
}

int main()
{
  printf("%d\n", heavy_loop(0));
  return 0;
}