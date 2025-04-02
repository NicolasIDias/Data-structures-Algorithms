#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
  int width;
  int height;
};
int main()
{

  /*
      O ponteiro é uma variável de endereço. São usados para acessar indiretamente os dados

      Porque usar: acessar o conteudo da memoria HEAP que não pode ser acessada diretamente pela função main do codigo

      Principal funçao: acessar recursos (arquivos, dispositivos ou valores de memoria) que estão fora do programa
      1. Acessar a memória heap
      2. Passagem de parametros
      3. Acesso à recursos

  */

  int a = 10;
  // Como declarar um ponteiro
  int *p;
  // Como inicializar um ponteiro
  // p está ocupando 2 bytes, o mesmo que a variavel 'a'
  // O valor de p é o valor que esta sendo armazenado no endereço de memória de 'a'
  p = &a;

  int arr[5] = {2, 4, 6, 8, 10};

  int *pt = arr;

  for (int i = 0; i < 5; i++)
    printf("%d\n", pt[i]);

  // Criar um array na memoria heap
  int *ptr;
  ptr = (int *)malloc(5 * sizeof(int));


  ptr[0] = 1, ptr[1] = 2, ptr[2] = 3, ptr[3] = 4, ptr[4] = 5;
  printf("Tamanho do ponteiro: %d\n", sizeof(ptr));

  for (int i = 0; i < 5; i++)
    printf("%d\n", ptr[i]);

  struct Rectangle *rect;
  int *n;
  printf("Tamanho do ponteiro: %d\n", sizeof(ptr));

  free(ptr);
  printf("%d", *p);
  return 0;
}