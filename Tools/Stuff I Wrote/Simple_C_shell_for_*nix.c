
//A simple program written in C, opens a shell via execve, so linux only! 
//For windows I think system("cmd.exe /c dir c:\\") can be used inside your program
// for example int main(){system("cmd.exe /c dir c:\\")}


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

