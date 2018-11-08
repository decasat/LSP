/********************************************************************\
*	Filename: 01_syscall.c
* 
*	Description: System calling
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 07 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/unistd.h>
#include <sys/syscall.h>


#define __NR_mysyscall 333

_syscall0(long,mysyscall );

char progname[] = "01_syscall";
int main(int argc, char *argv[] )
{
	printf("Hello \'%s\' \n", progname );

	mysyscall();


	return	EXIT_SUCCESS;
}
