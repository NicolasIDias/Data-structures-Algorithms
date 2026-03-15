#include <stdio.h>
/*
Desafio: https://codeforces.com/problemset/problem/1692/A

A. Marathon
*/


int main()
{
  int t;           // Numero de casos de teste
  scanf("%d", &t); // Leitura do numero de testes

  while (t--) // Loop para cada caso de teste
  {
    int counter = 0; // Contador para numeros maiores que 'a'
    int a, b, c, d;

    // Leitura dos 4 numeros
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Contagem de quantos numeros sao maiores que 'a'
    if (a < b)
      counter++;
    if (a < c)
      counter++;
    if (a < d)
      counter++;

    // Exibe a contagem para esse caso de teste
    printf("%d\n", counter);
  }

  return 0;
}
