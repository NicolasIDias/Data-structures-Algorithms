#include <stdio.h>
/*
Desafio: https://codeforces.com/problemset/problem/732/A

A. Buy a Shovel
*/

// Programa para encontrar o menor numero de pazinhas que podem ser compradas sem troco

int main()
{
  int k, r; // k = preco de uma pazinha, r = moeda extra que Polycarp tem
  int counter = 1; // Contador de quantas pazinhas serao compradas

  scanf("%d %d", &k, &r); // Leitura do preco e da moeda extra

  int price = k; // Inicialmente, o preco e o de uma unica pazinha

  // Enquanto o preco total nao puder ser pago sem troco, aumenta o numero de pazinhas compradas
  while ((price % 10 != r) && (price % 10 != 0))
  {
    counter++; 
    price += k; // Adiciona mais uma pazinha ao preco total
  }

  // Exibe o numero minimo de pazinhas necessarias
  printf("%d", counter);

  return 0;
}
