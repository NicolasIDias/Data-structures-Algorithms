#include <stdio.h>
/*
Desafio: https://codeforces.com/problemset/problem/427/A

A. Police Recruits
*/

// Programa para calcular quantos crimes ficaram sem investigacao

int main()
{
  int n; // Numero total de eventos
  scanf("%d", &n);

  int untreated = 0, police = 0; // Contadores de crimes nao resolvidos e policiais disponiveis

  while (n--) // Loop para processar cada evento
  {
    int input;
    scanf("%d", &input); // Leitura do evento atual

    if (input >= 1)
    {
      police += input; // Adiciona novos policiais quando recrutados
    }
    if (input == -1)
    {
      if (police >= 1)
        police -= 1; // Se houver policiais disponiveis, um resolve um crime
      else
        untreated += 1; // Se nao houver policiais, o crime fica sem investigacao
    }
  }

  // Exibe o total de crimes sem investigacao
  printf("%d", untreated);
}
