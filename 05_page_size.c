/********************************************************************\
*	Filename: 05_page_size.c
* 
*	Description: PAGE details
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 06 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/user.h>

char progname[] = "05_page_size";

int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);


	printf(" PAGE_SIZE = %ld\n", PAGE_SIZE);
	printf(" PAGE_SHIFT = %d\n", PAGE_SHIFT);


	return EXIT_SUCCESS;
}
