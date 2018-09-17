#include <stdio.h>

void f(void);

int main(void)
{
  int i;

  for(i=0; i<10; i++) f();
  return 0;
}

void f(void)
{
  int j = 10;
  printf("%d", j);

  j++; /* This line has no lasting affect*/
}
