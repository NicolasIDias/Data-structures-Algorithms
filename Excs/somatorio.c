#include <stdio.h>

int sum(int n)
{
  if(n == 1) return 1;
  int j = 0;
  for(int i=1;i<=n;i++) j+=i;
  return j;
}

int main() 
{
  int n;
  scanf("%d", &n);

  printf("%d", sum(n));

  return 0;
}