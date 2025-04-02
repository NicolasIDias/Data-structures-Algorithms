#include <stdio.h>

// Exemplo sem caso

// void twoPointers(int arr[], int n)
// {
//   int left = 0; // Inicio do array
//   int right = n - 1 // Fim do array, no qual n=tamanho do array

//   while(left < right)
//   {
//     /*
//       Alguma operacao que utlize os 2 ponteiros como
//       arr[left] arr[right]
//     */
//     // Movimentacao dos ponteiros dependendo da condicao
//     if(/*condition*/) left++;
//     else right--;
//   }

// }

// Exemplo de uso
// retorna 1 para Target encontrado
// retorna 0 para Target nao encontrado

int findPairWithSum(int arr[], int n, int target)
{
  int left = 0;      // ponteiro inicial
  int right = n - 1; // ponteiro final

  while (left < right)
  {
    int currentSum = arr[left] + arr[right];

    if (currentSum == target)
    {
      printf("Par encontrado %d + %d = %d", arr[left], arr[right], target);
      return 1;
    }
    /*
      Se a soma for menor que o target, movemos left para a direita (aumentamos a soma).
      Se a soma for maior que o target, movemos right para a esquerda (diminuímos a soma).
    */
    if (currentSum < target)
      left++;
    else
      right--;
  }
  return 0;
}

int main()
{
  // Array deve ser ordenado do maior para o menor
  int arr[] = {0, 1, 3, 4, 5, 9, 12, 66, 77};
  // Soma alvo
  int target = 80;
  // Tamanho do array
  int n = sizeof(arr) / sizeof(arr[0]);

  findPairWithSum(arr, n, target);

  return 0;
}