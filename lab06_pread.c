/********************************************************************\
*	Filename: llab06_pread.c
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

char progname[] = "llab06_pread";

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[128];
	int sz;
	int offset;
	int location;
	char newbuf[5] = "BBBB";

	fd = open("input.txt", O_RDWR);
	if (fd < 0) {
		perror("open");
		return -1;
	}

	location = lseek(fd, 0, SEEK_CUR);
	printf("Current location at opening file : %d\n", location);


	location = lseek(fd, 0, SEEK_END);
	printf("Current location : %d\n", location);

	sz = 4;
	offset = 5;
	sz = pread(fd, buf, sz, offset);
	if (sz < 0) {
		perror("pread");
		return -1;
	}
	buf[sz] = 0;
	puts(buf);

	sz = 4;
	offset = 5;

	sz = pwrite(fd, "BBBB", sz, offset);


	//buf[sz] = 0;
	//puts(buf);


	location = lseek(fd, 0, SEEK_CUR);
	printf("Current location : %d\n", location);


	close(fd);
	return EXIT_SUCCESS;
}
