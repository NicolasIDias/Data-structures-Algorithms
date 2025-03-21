#include <stdio.h>

struct Carta
{
  // 0==paus 1=espada 2=ouro 3=copas
  int shape;

  // a='1' 2='2' 3='3' ... j='11' q='12' k='13'
  int face;

  // 0=vermelho 1=preto
  int color;
}

main()
{
  struct Carta c1;

  // Criando um as de espadas carta preta
  c1.shape = 1;
  c1.face = 1;
  c1.color = 1;

  // Posso tambem inicializar a estrutura diretamente atribuindo os valores desejados
  // Exemplo: 2 de ouros carta verrmelha
  struct Carta c2 = {2, 2, 0};

  // Criando um baralho. Exemplo de array do tipo Carta
  // Exemplo de um baralho com 3 cartas para fins de teste
  struct Carta baralho[3] =
  {
    {1,1,1},
    {2,4,0},
    {3,12,1} 
  };

  // Imprime os atributos da primeira carta {1,1,1} = as de espadas carta preta
  printf("%d", baralho[0].face);
  printf("%d", baralho[0].shape);
  printf("%d", baralho[0].color);

}