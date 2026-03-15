#include <stdio.h>
#include <math.h>
int main()
{
    // mid = 2,2
    int mat[5][5];
    int indexI, indexJ;
    int i, j;
    int counter;

    // Laco que le os elementos da matriz e encontra a posicao do '1'
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int n;
            scanf("%d", &n);
            if (n == 1)
            {
                indexI = i;
                indexJ = j;
            }
            mat[i][j] = n;
        }
    }

    // Calcula a distancia do '1' ate o centro da matriz
    counter = abs(indexI - 2) + abs(indexJ - 2);

    // Imprime o nuero de movimentos necessarios
    printf("%d", counter);

    // Calculate distance between two points
    // while (indexI != 2)
    // {
    //     if (indexI > 2)
    //         indexI--;
    //     else if (indexI < 2)
    //         indexI++;
    //     counter++;
    // }
    // while (indexJ != 2)
    // {
    //     if (indexJ > 2)
    //         indexJ--;
    //     else if (indexJ < 2)
    //         indexJ++;
    //     counter++;
    // }
    // printf("%d", counter);
    return 0;
}