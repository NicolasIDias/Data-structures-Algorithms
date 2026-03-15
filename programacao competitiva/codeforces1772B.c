#include <stdio.h>

// Funcao que verifica se os quatro numeros formam uma condicao
int is_beautiful(int a, int b, int c, int d)
{
    return (a < b && c < d && a < c && b < d);
}

int main()
{
    int t;
    scanf("%d", &t);

    // Laco que processa os casos de teste
    while (t--)
    {
        int a, b, c, d;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &c, &d);

        // Verifica se existe alguma combinacao que satisfaca a condicao
        if (is_beautiful(a, b, c, d) ||
            is_beautiful(c, a, d, b) ||
            is_beautiful(d, c, b, a) ||
            is_beautiful(b, d, a, c))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}