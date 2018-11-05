/********************************************************************\
*	Filename: llab2-fops.c
* 
*	Description: File operations demo
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "llab2-fops";

int main(int argc, char *argv[])
{

	int nb, fdin, fdout;
	char buf[4096];
	char cmd[25];
	int pid;
	printf("Hello \'%s\' \n", progname);
	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);

	printf("fdin = %d, fdout = %d\n", fdin, fdout);

	getchar();

	sprintf(cmd, "ls -l /proc/%d/fd/ \n", getpid());

	system(cmd);

	getchar(); /* now go and check in /proc/<pid>/fd* */

	while ((nb = read(fdin, &buf, 4096)) > 0)
		write(fdout, &buf, nb);

	getchar(); /* now go and check in /proc/<pid>/fd* */
	printf("Now go and check in /proc/%d/fd/* \n", getpid());

	close(fdin);
	close(fdout);

	return EXIT_SUCCESS;

	/* exit()
	 * _exit()
	 * _Exit()
	 */
}
