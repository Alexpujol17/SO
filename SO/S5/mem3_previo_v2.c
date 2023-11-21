#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define REGION_SIZE		4096

int *p;

void func() 
{
  char buff[200];
  sprintf(buff,"Error\n");
  write(1,buff,strlen(buff));
  exit(1);
}

int
main (int argc, char *argv[])
{
  struct sigaction t;
  t.sa_handler = func;
  sigemptyset(&t.sa_mask);
  t.sa_flags = 0;
  sigaction(SIGSEGV, &t, NULL);


  char buff[256];

  sprintf (buff, "Addresses:\n");
  write (1, buff, strlen (buff));
  sprintf (buff, "\tp: %p\n", &p);
  write (1, buff, strlen (buff));

  *p = 5;

  sprintf (buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
  write (1, buff, strlen (buff));

  exit (0);

}