#include <stdio.h>
/*
Desafio: https://codeforces.com/problemset/problem/510/A

A. Fox And Snake
*/

// Programa para imprimir um padrao de cobra em um grid de tamanho n x m

int main()
{
  int n, m;
  scanf("%d %d", &n, &m); // Leitura das dimensoes do grid

  for (int j = 0; j < n; j++) // Loop para cada linha do grid
  {
    if (j % 2 == 0) // Linhas pares sao completamente preenchidas com '#'
    {
      for (int i = 0; i < m; i++)
      {
        printf("#");
      }
    }
    else // Linhas impares alternam entre comeco e fim
    {
      if ((j / 2) % 2 == 0) // Se for a primeira linha impar ou alternada, '#' no final
      {
        for (int i = 0; i < m - 1; i++)
        {
          printf(".");
        }
        printf("#");
      }
      else // Se for a segunda linha impar ou alternada, '#' no comeco
      {
        printf("#");
        for (int i = 0; i < m - 1; i++)
        {
          printf(".");
        }
      }
    }
    printf("\n"); // Pula para a proxima linha
  }
}
