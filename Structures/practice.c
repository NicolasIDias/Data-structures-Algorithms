#include <stdio.h>

struct Rect {

  int length;
  int width;

};

int main(){

  struct Rect r;

  int l,w;
  scanf("%d %d", &l,&w);

  r.length = l;
  r.width = w;

  int area = l*w;

  printf("Tamanho em bytes da struct Rect = %d\n", sizeof(r));
  printf("Area = %d\n", area);

  return 0;
}