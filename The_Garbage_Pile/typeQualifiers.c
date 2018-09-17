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
    //error code
    //if(*str== ' ')  *string = '-';
    if(*str== ' ') printf("%c", '-');
    
  //replaces each space in the string but only when printed
  //we cannot modify the str, due to declaring the original value as a const

    else printf("%c", *str);
    str++;
  }
}
