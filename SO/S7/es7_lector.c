#include <string.h>
#include <stdio.h>
#include <unistd.h>

int
main ()
{
  int numero;
  read (0, &numero, sizeof (int));
  char buff[10];
  sprintf(buff,"%d\n",numero);
  write(1,buff,strlen(buff));

}