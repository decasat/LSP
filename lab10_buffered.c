/*******************************************************\
 * Bufferred and unbuffered IOs 			*
 * Author : Sateesh Kumar G				*
\*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	printf("Hello \n");
//	fflush(stdout);
	write(1, "world ", 6);

	printf("\n");

	exit(-1);
}

