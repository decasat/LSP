/********************************************************************\
*	Filename: 02_cd_pwd.c
* 
*	Description: Demo getcd and pwd
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 06 NOV 2018
\********************************************************************/
/* shows the eefect of chdir and getcwd , Highlights of using
 * cd command in shell ( we will show this by implementing our own
 * shell.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

char progname[] = "02_cd_pwd";

int main(int argc, char *argv[])
{



	char *ptr;
	int maxpathsize;
	maxpathsize = pathconf("/", _PC_PATH_MAX);
	ptr = (char *) malloc(maxpathsize);
	if (getcwd(ptr, maxpathsize) == NULL) {
		perror("prog:");
		exit(1);
	}
	printf("cwd = %s\n", ptr);
	if (chdir(argv[1]) < 0) {
		perror("prog:");
		exit(1);
	}
	if (getcwd(ptr, maxpathsize) == NULL) {
		perror("prog:");
		exit(1);
	}
	printf("cwd = %s\n", ptr);
}
