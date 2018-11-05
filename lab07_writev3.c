/********************************************************************\
 *	Filename: lab07_writev3.c
 * 
 *	Description: readv-writev-Demo
 *	programmer: Sateesh Kumar G <contact@sateeshkg.com>
 *	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define NVEC 3

int main()	
{

	  char *str0 = "hello ";
	  char *str1 = "world\n";
	  char *str2 = "satesh\n";

	  struct iovec iov[NVEC];
	  ssize_t nwritten;

	  int fd;

         iov[0].iov_base = str0;
         iov[0].iov_len = strlen(str0);

         iov[1].iov_base = str1;
         iov[1].iov_len = strlen(str1);
         
	 iov[2].iov_base = str2;
         iov[2].iov_len = strlen(str2);


         unlink("./newfile");
         if((fd = open ("./newfile", O_RDWR | O_CREAT, 0666)) < 0)
		 perror("open");

	printf(" file descriptor %d\n", fd);

        nwritten = writev(fd, iov, 3);

	return 0;
}

