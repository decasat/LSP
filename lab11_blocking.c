/****************************************************************\
 * Blocking IO smaple 						*
 * Author : SAteesh Kumar G					*
 * **************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

char buffer[4096];

int main(int argc, char **argv)
{
	int delay = 1, n, m = 0;

	if (argc > 1)
		delay = atoi(argv[1]);

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
