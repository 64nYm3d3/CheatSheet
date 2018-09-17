/*
A string is created and unable to be modified
Here, its declared as a const, which is great for placing a variable in ROM
While we may not be able to hardcode a change of the variable,
we can manipulate it as it's sent to stdout and 
while it doesn't keep a variable from being manipulated
it proves changes to a variable occurred because of external events
*/


#include <stdio.h>

void sp_t_dash(const char *str);

int main(void)
{
  sp_t_dash("This is a test");

return(0);
}

void sp_t_dash(const char *str)
{
  while(*str)
  {
    /***error code***
    if(*str== ' ')  *string = '-';
    */
    if(*str== ' ') printf("%c", '-');  //Replaces each space in the string with a '-' but only when printed

    else printf("%c", *str);
    str++;
  }
}
