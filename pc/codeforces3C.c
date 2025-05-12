#include <stdio.h>

int main()
{
  char b[3][4];
  int i, j;
  int xcount = 0, ocount = 0;
  int winX = 0, winO = 0;

  for (i = 0; i < 3; i++)
    scanf("%3s", b[i]);
  // Contagem das ocorrencias de 'X' e 'O'
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      if (b[i][j] == 'X')
        xcount++;
      else if (b[i][j] == '0')
        ocount++;
    }

  // Verifica as linhas e colunas para identificar se alguem venceu

  for (i = 0; i < 3; i++)
  {
    if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
    {
      if (b[i][0] == 'X')
        winX = 1;
      else if (b[i][0] == '0')
        winO = 1;
    }
    if (b[0][i] == b[1][i] && b[1][i] == b[2][i])
    {
      if (b[0][i] == 'X')
        winX = 1;
      else if (b[0][i] == '0')
        winO = 1;
    }
  }
  // Verifica as diagonais para identificar vitória
  if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
  {
    if (b[0][0] == 'X')
      winX = 1;
    else if (b[0][0] == '0')
      winO = 1;
  }
  if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
  {
    if (b[0][2] == 'X')
      winX = 1;
    else if (b[0][2] == '0')
      winO = 1;
  }

  // Verifica condicoes ilegais
  if (!(xcount == ocount || xcount == ocount + 1))
  {
    printf("illegal\n");
  }
  else if (winX && winO)
  {
    printf("illegal\n");
  }
  else if (winX && xcount == ocount + 1)
  {
    printf("the first player won\n");
  }
  else if (winO && xcount == ocount)
  {
    printf("the second player won\n");
  }
  else if (!winX && !winO && xcount + ocount == 9)
  {
    printf("draw\n");
  }
  else if (!winX && !winO)
  {
    if (xcount == ocount)
      printf("first\n");
    else
      printf("second\n");
  }
  else
  {
    printf("illegal\n");
  }

  return 0;
}
