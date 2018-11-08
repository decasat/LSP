/********************************************************************\
*	Filename: 04_mknod.c
* 
*	Description: mknod() usage
*	Programmer: Sateesh Kumar G <contact@>
*	Date: 06 NOV 2018
\********************************************************************/

#define  _BSD_SOURCE || _SVID_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "04_mknod";

// for creating dev_t use  dev_t makedev(int maj, int min);
int main(int argc, char *argv[])
{
	printf("Hello \'%s\' \n", progname);


	int ret;
	char name[10];
	dev_t p;

	p = makedev(300, 0);
	perror("dev:");
	printf("mknod demo\n");
	printf("Enter the pipename to create: ");
	scanf("%s", name);
	ret = mknod(name, 0666 | S_IFCHR, p);

	//      ret = mknod(name,0666 | S_IFIFO,NULL);

	if (ret < 0)
		printf("mknod failed\n");
	else
		printf("mknod success\n");

	return 0;

}
