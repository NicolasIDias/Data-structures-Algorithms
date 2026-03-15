#include <stdio.h>
/*
Desafio: https://codeforces.com/problemset/problem/151/A

A. Soft Drinking
*/

// Declaracao das variaveis para armazenar os valores de entrada
int main()
{
  int n, k, l, c, d, p, nl, np, mlt, lt, st;

  // Leitura dos valores fornecidos pelo usuario
  scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

  // Calcula a quantidade total de toasts possiveis para cada ingrediente
  mlt = (k * l) / nl; // Numero de toasts possiveis com a quantidade total de bebida
  lt = c * d;         // Numero de toasts possiveis com a quantidade total de fatias de limao
  st = p / np;        // Numero de toasts possiveis com a quantidade total de sal

  // Determina o menor valor entre as tres possibilidades, pois isso define o maximo de toasts possiveis
  int min = mlt;
  if (lt < min)
    min = lt;
  if (st < min)
    min = st;

  // Divide pelo numero de amigos para obter o numero de toasts que cada um pode fazer
  printf("%d", min / n);

  return 0;
}
