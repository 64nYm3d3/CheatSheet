# Buffer Overflows

I LOVE THIS STUFF

Table



## Introduction to the concept

Mishandled memory by the code, more data is getting sent to a fixed length memory block (or a buffer) than it can handle allowing an attacker to overwrite addresses in the memory allocated to the application.

### Complicated stuff right?

Lets take a look at an example
~~~
// A C program to demonstrate buffer overflow
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
       // Reserve 5 byte of buffer plus the terminating NULL.
       // should allocate 8 bytes = 2 double words,
       // To overflow, need more than 8 bytes...
       char buffer[5];  // If more than 8 characters input
                        // by user, there will be access
                        // violation, segmentation fault

       // a prompt how to execute the program...
       if (argc < 2)
       {
              printf("strcpy() NOT executed....\n");
              printf("Syntax: %s <characters>\n", argv[0]);
              exit(0);
       }
 
       // copy the user input to mybuffer, without any
       // bound checking a secure version is srtcpy_s()
       strcpy(buffer, argv[1]);
       printf("buffer content= %s\n", buffer);
 
       // you may want to try strcpy_s()
       printf("strcpy() executed...\n");
 
       return 0;
}
~~~
Hopefully this helps. 

We know **char** will allocate memory in increments of  32 bits (a dword) to addresses in memory to store it’s variable, since we have indicated we need 5 bytes in our stored variable, it will allocate 64 bits of space for the variable **buffer**.

So if we have input ~~~ 0123 4567~~~ (64 bits allocated & 24 bits beyond intended) it will run smoothly, because there are 8 characters, each one only taking up 1 byte of space even though it’s beyond our allocated buffer length. However if we input ~~~ 0123 4567 8~~~ our program will crash since we have just written 1 byte beyond our allocated addresses into another. This is a segmentation fault, accessing memory that does not belong to you.

### Okay but how is crashing the program result in exploitation?

To put it simply, we are **freely able to write to memory addresses and execute it** since the program does not stop executing the instruction set loaded into memory. So we may be able to execute a small amount of code that realistically may allow us to redirect, introduce, and execute our own arbitrary code for a shell into a limited space allocated for the program by the system.

## Entry level buffer overflow

The quote that got me interested in this... 

*"Nice work. You can copy the PoC exploit code, run it, see that it doesn’t work (or if you are lucky, conclude that it works), or… you can try to understand the process of building the exploit so you can correct broken exploits, or just build your own exploits from scratch. (or if you are lucky, conclude that it works), or… you can try to understand the process of building the exploit so you can correct broken exploits, or just build your own exploits from scratch."*

---
Refs:
https://www.corelan.be/index.php/2009/07/19/exploit-writing-tutorial-part-1-stack-based-overflows/
https://github.com/justinsteven/dostackbufferoverflowgood (I cloned this repo)
