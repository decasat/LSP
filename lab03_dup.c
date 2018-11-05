/********************************************************************\
 *	Filename: lab03_dup.c
 * 
 *	Description: dup() system call demo
 *	programmer: Sateesh Kumar G 
 *	date begun: 05 NOV 2018
\********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
 
int main()
{
    int fd;
 
    // create a text file 'output.txt'
    fd = open("output.txt", O_CREAT|O_RDWR, 0666);

    getchar();
 
    // redirect standard output to 'output.txt'
    close(1);
    
    getchar();
    dup(fd);

    getchar();
    
    close(fd);
 
    // print the string to 'output.txt' 
    printf("hello world! readdy\n");
    return 0;
}
