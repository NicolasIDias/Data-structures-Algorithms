#include <stdio.h>

// funcao recursiva que conta os caminhos validos para alcancar 'pos'
int valid(int pos, int dreamoon, int untrack)
{
  // caso nao haja mais '?' para decidir
  if (untrack == 0)
    return (pos == dreamoon) ? 1 : 0; // retorna 1 se chegou no destino correto, senao retorna 0

  // testa os dois caminhos possiveis para cada '?':
  // '+' e chama recursivamente com dreamoon + 1
  // '-' e chama recursivamente com dreamoon - 1
  return valid(pos, dreamoon + 1, untrack - 1) + valid(pos, dreamoon - 1, untrack - 1);
}

int main()
{
  char c;           // variavel para ler cada caractere de entrada
  int pos = 0;      // posicao final desejada
  int dreamoon = 0; // posicao real do Dreamoon com os comandos reconhecidos
  int untrack = 0;  // contador de '?'
  int run = 1;      // variavel de controle para os loops de leitura (simula um break)

  while (run == 1)
  {
    if (scanf("%c", &c) == EOF || c == '\n') // para o loop quando atinge o final da linha
      run = 0;
    else if (c == '+') // aumenta a posicao 
      pos++;
    else // diminui a posicao
      pos--;
  }

  run = 1; // reseta a variavel para ler s2

  while (run == 1)
  {
    if (scanf("%c", &c) == EOF || c == '\n') // para o loop quando atinge o final da linha
      run = 0;
    else if (c == '+') // aumenta a posicao do draemoon
      dreamoon++;
    else if (c == '-') // diminui a posicao do draemoon
      dreamoon--;
    else // aumenta a cada comando nao reconhecido
      untrack++;
  }

  // se nao houver '?', a probabilidade e 1 ou 0
  if (untrack == 0)
  {
    printf("%.9f", (pos == dreamoon) ? 1.0 : 0.0);
    return 0;
  }

  // calcula o total de possibilidades de comandos (2^untrack)
  int total = 1;
  for (int i = 0; i < untrack; i++)
    total *= 2;

  // conta quantos dos caminhos possiveis chegam na posicao correta
  int validas = valid(pos, dreamoon, untrack);

  // probabilidade = o que eu quero(validas) / total de movimentos

  // calcula a probabilidade e imprime com 9 casas decimais de precisao
  printf("%.9f", (double)validas / total);

  return 0;
}
