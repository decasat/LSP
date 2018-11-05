/********************************************************************\
*	Filename: llab05_lseek.c
* 
*	Description: Demo of lseek() system call
*	programmer: Sateesh Kumar G
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "llab05_lseek";

int main()
{
	int fd;
	off_t offset;
	unlink("./newfile");

	getchar();

	fd = open("./newfile", O_RDWR | O_CREAT, 0644);
	if (fd < 0) {
		perror("file :");
		exit(1);
	}
	write(fd, "123", 3);
	printf("...............\n");
	offset = lseek(fd, 0, SEEK_CUR);
	perror("lseek:");
	printf("current file offset is at %ld\n", offset);

	write(fd, "456", 3);
	write(fd, "789", 3);
	write(fd, "abc", 3);
	offset = lseek(fd, 0, SEEK_CUR);

	printf("current file offset is at %ld\n", offset);
	getchar();

	offset = lseek(fd, -6, SEEK_CUR);
	printf("current file offset is at %ld\n", offset);
	write(fd, "xyz", 3);

	offset = lseek(fd, 0, SEEK_CUR);

	printf("current file offset is at %ld\n", offset);
	getchar();
	close(fd);
}
