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


#define decode(s,t,u,m,p,e,d) m##s##u##t
#define begin decode(a,n,i,m,a,t,e)

void begin()
{
	printf("Hello : without-main-2\n");

}

