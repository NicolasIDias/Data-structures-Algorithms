#include <stdio.h>

int a[100005]; // Declaramos o array globalmente para evitar problemas de tamanho de pilha

// Funcao para calcular o GCD de dois numeros usando o algoritmo de Euclides
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  // Calculamos o GCD de todos os elementos porque qualquer x que divide todos os elementos deve dividir o GCD
  // Isso nos permite verificar de forma eficiente se tal x existe, em vez de verificar cada x contra todos os elementos
  int g = a[0];
  for (int i = 1; i < n; i++)
  {
    g = gcd(g, a[i]);
    if (g == 1)
      break; // Otimizacao: o GCD nao pode ser menor que 1
  }

  // Verificamos se algum x no array divide o GCD
  // Se x divide o GCD, entao x divide todos os elementos, pois o GCD divide cada elemento
  // Alem disso, se x divide todos os elementos, entao x divide o GCD
  // Portanto, x divide todos os elementos se e somente se x divide o GCD
  int found = 0;
  for (int i = 0; i < n; i++)
  {
    if (g % a[i] == 0)
    {
      printf("%d\n", a[i]);
      found = 1;
      break; // Imprimimos o primeiro x que encontramos
    }
  }

  // Se nao encontramos nenhum x que divide o GCD, entao nao existe tal numero
  // Nesse caso, imprimimos -1
  if (found == 0)
  {
    printf("-1\n");
  }

  return 0;
}