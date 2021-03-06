/********************************************************************\
*	Filename: lab12_non_blocking.c
* 
*	Description: Demo non blocking applicatio
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char progname[] = "lab12_non_blocking";

char buffer[4096];

int main(int argc, char **argv)
{
	int delay = 1, n, m = 0;

	if (argc > 1)
		delay = atoi(argv[1]);
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);	/* stdin */
	fcntl(1, F_SETFL, fcntl(1, F_GETFL) | O_NONBLOCK);	/* stdout */

	while (1) {
		n = read(0, buffer, 4096);
		if (n >= 0)
			m = write(1, buffer, n);
		if ((n < 0 || m < 0) && (errno != EAGAIN))
			break;
		sleep(delay);
	}
	perror(n < 0 ? "stdin" : "stdout");
	exit(1);
}

/***************************************************************************/
