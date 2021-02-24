#include <stdio.h>

int a = 43;

int foo(int x){
  x = 5;
  a = 5;
  printf("%d %d\n",x,a);
  return 0;
}


int main(void)
{

  int x = 4;

  int s = foo(x);

  printf("%d %d",x,a);

  return 0;


}

