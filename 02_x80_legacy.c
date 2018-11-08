/********************************************************************\
*	Filename: 05_x80_legacy.c
* 
*	Description: x80 32 bit platform
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 07 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>

char progname[] = "05_x80_legacy";

int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);

	int r;
	__asm__("movl $332, %eax");
	__asm__("int $0x80");
	__asm__("movl %eax, -4(%ebp)");
	printf("%d\n", r);


	return EXIT_SUCCESS;
}
