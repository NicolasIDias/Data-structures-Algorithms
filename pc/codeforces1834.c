#include <stdio.h>

int main()
{
  int t;
  scanf("%d", &t);

  while (t--)
  {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    int par_neg = 0; // 0 se ha numero par de -1; 1 se impar

    // Leitura e contagem:
    // sum acumula soma dos valores
    // par_neg rastreia, mod 2, quantos valem -1
    for (int i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      sum += x;
      if (x == -1)
      {
        par_neg ^= 1;
      }
    }

    // 1) Tornar soma nao negativa:
    // Cada troca de -1 para +1 adiciona +2
    // Se sum < 0, trocas = ceil((-sum)/2)
    int trocas_soma = 0;
    if (sum < 0)
    {
      trocas_soma = (int)((-sum + 1) / 2);
    }

    // 2) Garantir produto nao negativo:
    // Produto e (-1)^(# de -1). Queremos par_neg final = 0
    // Cada troca inverte par_neg. Se apos trocas_soma ainda for 1,
    // precisamos de mais uma troca
    int total = trocas_soma;
    if ((par_neg ^ (trocas_soma & 1)) == 1)
    {
      total++;
    }

    printf("%d\n", total);
  }

  return 0;
}
