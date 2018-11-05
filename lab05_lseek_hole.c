/********************************************************************\
*	Filename: llab05_lseek_hole.c
* 
*	Description: Demo of lseek() hole
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

char progname[] = "llab05_lseek_hole";

int main(int argc, char **argv)
{
	char *filename = "AB";
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	int offset = (argc > 1) ? atoi(argv[1]) : 1000000;
	struct stat statbuf;

	write(fd, "A", 1);
	lseek(fd, offset, SEEK_SET);
	write(fd, "B", 1);
	close(fd);
	stat(filename, &statbuf);
	printf("The file %s has size %lld and takes %lld sectors\n",
	       filename, (long long) statbuf.st_size,
	       (long long) statbuf.st_blocks);
	return 0;
}
