/********************************************************************\
*	Filename: llab06_pwrite.c
* 
*	Description: Positional read and write pr
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "llab06_pwrite";
int main()
{
	int fd;
	int count;
	int offset;

	fd = creat("output.txt", 0666);
	if (fd < 0) {
		perror("open");
		return -1;
	}

	count = 6;
	offset = 4;
	count = pwrite(fd, "satesh", count, offset);
	if (count < 0) {
		perror("pwrite");
		return -1;
	}

	count = 3;
	offset = 0;
	count = pwrite(fd, "123", count, offset);
	if (count < 0) {
		perror("pwrite");
		return -1;
	}

	close(fd);
	return 0;
}
