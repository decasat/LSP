/********************************************************************\
*	Filename: lab13_swab.c
* 
*	Description: Demo swap and swab
*	programmer: Sateesh Kumar G <contact@sateeshkg.com>
*	date begun: 05 NOV 2018
\********************************************************************/


/*
 * void swab(const void *from, void *to, ssize_t n)
 *
 * The swab() function copies n bytes from the array pointed to by from to 
 * the array pointed to by to, exchanging adjacent even and odd bytes. 
 * This function is used to exchange data between machines that have different low/high byte ordering.
 * */




#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>

void dump(void *array, ssize_t n)
{
	int i;
	char *chars = (char *) array;

	for (i = 0; i < n; i++)
		printf("%#x ", chars[i]);
	printf("\n");
}

void swap(void *from, void *to, ssize_t n)
{

	swab(from, to, n);
	dump(from, n);
	dump(to, n);
}

int main()
{
	int i = 0x44332211;
	int j;
	char from[] = { 0x11, 0x22, 0x33, 0x44 };
	char to[4];

	swap(&i, &j, sizeof(i));
	swap(from, to, sizeof(from));
	return 0;
}
