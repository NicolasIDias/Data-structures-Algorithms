#include <stdio.h>

int main()
{
    int notaFinal;
    scanf("%d", &notaFinal);

    if(notaFinal >= 60) printf("Passou\n");
    else if((notaFinal >= 45) && (notaFinal < 60)) printf("Recuperacao\n");
    else printf("Reprovado\n");
    
    return 0;
}
