/*

  Objetivo: Calcular todos os numeros ate nO numero de fibonacci

 */


#include <stdio.h>

int main()
{

  int n, a = 0, b = 1;
  scanf("%d", &n);
  int temp;

  for (int i = 1; i <= n; i++)
  {
    temp = a + b;
    a = b;
    b = temp;

    printf("%d ", a);
  }

  return 0;
}