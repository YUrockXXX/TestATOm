#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE = 100;
int main()
{
  char buffer[MAXSIZE];
  unsigned int count = 0;
  fgets(buffer, MAXSIZE, stdin);
  puts(buffer);


	return 0;
}
