#include <stdio.h>

int main()
{

  int a,b,c;
  scanf("%d %d %d", &a,&b,&c);

  if(a+b+c != 180){
    printf("Nao e um triangulo valido");
    return 0;
  }

  if((a == 90) || (b == 90) || (c == 90)) printf("Retangulo");
  if((a < 90) && (b < 90) && (c < 90)) printf("Acutangulo");
  if((a > 90) || (b > 90) || (c > 90)) printf("Obtusangulo");

  return 0;
}