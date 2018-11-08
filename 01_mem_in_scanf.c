/********************************************************************\
*	Filename: 01_mem_in_sscnf.c
* 
*	Description: Allocate mem in scanf
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "01_mem_in_sscnf";

int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);


	char *p;

	printf("Enter string here :  ");

	scanf("%ms", &p);
	printf("\n%s\n", p);

	free(p);

	return EXIT_SUCCESS;
}
