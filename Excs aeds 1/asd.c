#include <stdio.h>

#define SIZE 2

void multiply(int F[SIZE][SIZE], int M[SIZE][SIZE])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[SIZE][SIZE], int n)
{
    if (n == 0 || n == 1)
        return;

    int M[SIZE][SIZE] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F); 

    if (n % 2 != 0)
        multiply(F, M); 
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    int F[SIZE][SIZE] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}

int main()
{
    int n;
    printf("Digite o termo de Fibonacci que quer calcular: ");
    scanf("%d", &n);

    printf("Fibonacci de %d e: %d\n", n, fibonacci(n));

    return 0;
}
