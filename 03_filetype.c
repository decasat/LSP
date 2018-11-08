/********************************************************************\
*	Filename: 03_filetype.c
* 
*	Description: stat() fstat() lstat() demo
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 06 NOV 2018
\********************************************************************/
/****************************************************************\
 * Description : stat() lstat() fstat() systemcall demo		*
\****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char progname[] = "03_filetype";

int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);

	int i;
	struct stat buf;
	char *ptr;
	if (argc != 2) {
		printf("Usage: ftype filename\n");
		exit(2);
	}
	printf("%s: ", argv[1]);
	if (stat(argv[1], &buf) < 0) {
		perror("lstatfailed:");
		exit(1);
	}

	if (S_ISREG(buf.st_mode))
		ptr = "regular";
	else if (S_ISDIR(buf.st_mode))
		ptr = "directory";
	else if (S_ISCHR(buf.st_mode)) {
		ptr = "character special";
		printf("Major = %d \n", major(buf.st_rdev));
		printf("Minor = %d \n", minor(buf.st_rdev));
	} else if (S_ISBLK(buf.st_mode))
		ptr = "block special";
	else if (S_ISFIFO(buf.st_mode))
		ptr = "fifo";
	else if (S_ISLNK(buf.st_mode))
		ptr = "symbolic link";
	else
		ptr = "** unknown mode **";
	printf("File Type :  %s\n", ptr);
	printf(" file owner = %d \n", buf.st_uid);
	printf(" file group = %d \n", buf.st_gid);
	printf(" file size = %ld \n", buf.st_size);
	printf(" block size = %ld \n", buf.st_blksize);
}

/* stat is same as lstat in case of lstat it gives statistics of link instead
 *  of file opinted by link. fstat is same as stat.
 *  */
