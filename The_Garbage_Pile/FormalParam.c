/*compare string s & c, return 1 if string c *s, is part of string c*/

int is_in(char *s, char c)
{
  while(*s)
    if(*s==c) return 1;
    else s++;
    
   return 0;
}
