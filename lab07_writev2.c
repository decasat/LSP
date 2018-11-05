/********************************************************************\
 *	Filename: lab07_writev2.c 
 * 
 *	Description: readv-writev-Demo
 *	programmer: Sateesh Kumar G <contact@sateeshkg.com>
 *	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <sys/uio.h>

#define 	NVECS 	4
#define 	BLEN 	10

#define DEATH(mess) 	{ perror(mess) ; exit(errno); }

int main(int argc, char *argv[])
{
	unlink("./junkfile");
	int fd, j;
	char *filename = "./junkfile";
	struct iovec iov[NVECS];


/* initialize NVEC structure and buffers */

	for (j = 0; j < NVECS; j++) {
		char *buf = malloc(BLEN);
		memset(buf, '0' + j, BLEN);
		iov[j].iov_base = buf;
		iov[j].iov_len = BLEN;
	}
	if ((fd = open("./junkfile", O_RDWR | O_CREAT, 0666)) < 0)
		DEATH("open");

	printf("pid %d\n", getpid());
	printf("File descriptor number %d\n", fd);
	getchar();
/* write the buffer out to the junkfile */

	if (writev(fd, iov, NVECS) < 0)
		DEATH("write");

	getchar();
/*clear out the buffer */
	for (j = 0; j < NVECS; j++) {
		char *buf = malloc(BLEN);
		memset(buf, '0', BLEN);
	}

/* repositioning of file pointer */
	if ((j = lseek(fd, 0, SEEK_SET)) > 0)
		DEATH("lseek:");
	/*read the buffer back from the junkfile */
	if (readv(fd, iov, NVECS) < 0)
		DEATH("readv");
	for(j = 0; j < NVECS ; j++)
	printf("%s\n", iov[j]);
	
	getchar();

	printf("I am at the end\n");

	close(fd);

}
