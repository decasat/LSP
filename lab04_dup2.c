/********************************************************************\
*	Filename: llab04_dup2.c
* 
*	Description: dup2() system call demo
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "llab04_dup2";

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;

	// create a text file 'output.txt'
	fd = open("output.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);

	// redirect standard output to 'output.txt'
	dup2(fd, 1);
	close(fd);

	// print the string to 'output.txt' 
	printf("hello world! Demo of dup system call\n");
	exit(123);
}
