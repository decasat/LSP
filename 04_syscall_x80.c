/********************************************************************\
*	Filename: 04_syscall_x80.c
* 
*	Description: Using x80 for 32 bit platform
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 07 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "04_syscall_x80";

int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);


	unsigned int syscall_nr = 1;
	int exit_status = 22;

      asm("movl %0, %%eax\n" "movl %1, %%ebx\n" "int $0x80":	/* output parameters, we aren't outputting anything, no none */
	/* (none) */
      	:			/* input parameters mapped to %0 and %1, repsectively */
	"m"(syscall_nr), "m"(exit_status)
      	:			/* registers that we are "clobbering", unneeded since we are calling exit */
	"eax", "ebx");
}
