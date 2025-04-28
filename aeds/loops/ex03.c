#include <stdio.h>

int main()
{

  int n;

  scanf("%d", &n);

  for(int i=0;i<n;i++)
  {
    for(int j=n;j>0;j--){
      if((i%2!=0) && (j%2!=0)) printf("*");
      else if((i%2==0) && (j%2==0)) printf("*");
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}