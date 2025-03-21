#include <stdio.h>

// Definição da estrutura Carta para representar cartas de baralho
struct Carta
{
  // 0 == Paus, 1 == Espadas, 2 == Ouros, 3 == Copas
  int naipe;

  // Valores: 1 = Ás, 2-10 = Números, 11 = Valete (J), 12 = Dama (Q), 13 = Rei (K)
  int valor;

  // 0 = Vermelho (para Ouros/Copas), 1 = Preto (para Paus/Espadas)
  int cor;
}; 

int main()
{
  // Criação de carta manualmente
  struct Carta c1;

  // Atribuição individual dos valores (Ás de Espadas - carta preta)
  c1.naipe = 1;   // Espadas
  c1.valor = 1;    // Ás
  c1.cor = 1;      // Preto

  // Inicialização direta na declaração (2 de Ouros - carta vermelha)
  struct Carta c2 = {2, 2, 0}; // {naipe, valor, cor}

  // Criação de um "baralho" usando array de structs
  // Array fixo com 3 cartas pré-definidas para teste
  struct Carta baralho[3] = 
  {
    {1, 1, 1},   // Ás de Espadas (preto)
    {2, 4, 0},    // 4 de Ouros (vermelho)
    {3, 12, 1}    // Dama (Q) de Copas (preto)
  };

  // Impressão dos atributos da primeira carta do baralho
  // Resultado será "111" (valor, naipe, cor) sem formatação
  printf("%d", baralho[0].valor);
  printf("%d", baralho[0].naipe);
  printf("%d", baralho[0].cor);

  return 0;
}