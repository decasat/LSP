/********************************************************************\
 *	Filename: lab07_writev1.c
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

#define NVEC 3

int main()	
{

	  char *str0 = "hello ";
	  char *str1 = "world";
	  char *str2 = " bhaveen\n";

	  struct iovec iov[NVEC];
	  ssize_t nwritten;

         iov[0].iov_base = str0;
         iov[0].iov_len = strlen(str0);
	
	 iov[1].iov_base = str1;
         iov[1].iov_len = strlen(str1);
	
	 iov[2].iov_base = str2;
         iov[2].iov_len = strlen(str2);

        nwritten = writev(STDOUT_FILENO, iov, NVEC);
	getchar();

	return 0;
}
