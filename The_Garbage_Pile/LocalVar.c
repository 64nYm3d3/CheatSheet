#include <stdio.h>

int main(void)
{
  int x;
  x = 10;

  if(x == 10)
  {
  int x; /* this x is a separate variable from the outer x */

  x = 99;
  printf("Inner x: %d\n", x);
  }

  printf("Outer x: %d\n", x);

  return 0;
}
