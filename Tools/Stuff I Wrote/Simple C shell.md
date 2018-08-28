A simple program written in C, opens a shell via execve so linux only!


~~~
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *name[2];
  
  [0] = "/bin/sh";
  [1] = 0x0;

execve(name[0], name, 0x0);
exit(0)
}

~~~
