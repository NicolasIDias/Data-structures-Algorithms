#include <stdio.h>

int main()
{

  int n,k,l,c,d,p,nl,np,mlt,lt,st;

  scanf("%d %d %d %d %d %d %d %d", &n,&k,&l,&c,&d,&p,&nl,&np);

  mlt = (k*l)/nl;
  lt = c*d;
  st = p/np;
  int min=mlt;
  if(lt<min) min=lt;
  if(st<min) min=st;
  if(mlt<min) min=mlt;
  
  printf("%d", min/n);

  return 0;
}