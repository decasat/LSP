/********************************************************************\
*	Filename: without-main.c
* 
*	Description: Program without main() funct
*	Compilation : gcc -O3 -nostartfiles without_main.c
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 02 OCT 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "without-main";

int my_main(void);

/* prog_without_main.c */
int _start()
{
	_exit(my_main());
}

int my_main(void)
{
	printf("Hello: I have called without main\n");
	return 42;
}

