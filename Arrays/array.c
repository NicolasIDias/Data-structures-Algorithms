#include <stdio.h>

int main()
{
  // Array de tamanho 5 que recebe valores inteiros e que podem ser acessados atraves dos indices
  // Ocupa fixamente 20 bytes. 4 bytes por inteiro * tamanho pre definido do array
  // Se tentarmos acessar o indice 4 ou qualquer um que nao esteja inicializado, o valor predefinido dele sera 0
  int A[5] = {1, 2, 3, 4};

  // Definicao dos valores do array quando ele nao esta inicializado
  // A[0]=12;
  // A[1]=15;
  // A[2]=25;

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", A[i]);
  }

  // Array de tamanho "variavel"
  // Pode-se adicionar mais valores que o tamanho dele vai se expandir dinamicamente
  int B[] = {1, 2, 3, 4, 5, 6, 7};
  B[8] = 23;

  // O Array pode ter um tamanho personalizado
  int n;
  scanf("%d", &n);
  // O tamanho do array sera definido pelo inteiro n
  // O Array nao pode ser inicializado dessa forma: arr[n]={...}; Deve ser inicializado manualmente ou por um loop

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d\n", &arr[i]); // Le um valor pra arr no indice I
    printf("%d\n", arr[i]); // Imprime o valor de arr no indice I
  }

  // printf("%d\n", sizeof(B)); // Imprime quantos bytes o array B ocupa na memoria
  // printf("%d\n", A[4]);
  // printf("%d\n", B[8]);

  return 0;
}