/********************************************************************\
*	Filename: lab1-HS-link.c
* 
*	Description: Hard and Soft link demo
*		     Commands to create hard link
*		     ln <file1> <hardfile>
*		     link <file1> <hardfile>
*		     ln -s <file1> <softfile>
*
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <unistd.h> /* symlink() */
#include <errno.h>

char progname[] = "lab1-HS-link";

int main(int argc, char *argv[])
{
	int ret;

	printf("Hello \'%s\' \n", progname);

	ret = symlink("./file1", "./file1-soft");

	if (ret < 0)
	{
		printf("Symlink failed\n");
		perror("symlink:");
	}
	else
		printf("Symlink established\n");

	ret = link("./file1", "./file1-hard");

	if (ret < 0)
	{
		printf("Hardlink failed\n");
		perror("link:");
	}
	else
		printf("Hardlink established\n");


return EXIT_SUCCESS;
}
