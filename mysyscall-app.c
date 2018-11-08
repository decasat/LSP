#define _GNU_SOURCE
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>


/* #define __NR_mysyscall   333 => This line added in unistd.h */


int main()
{
	long ret;
	int pid;
	int pid1;


	ret = syscall(__NR_mysyscall);

	pid = syscall(SYS_getpid);
	pid1 = syscall(__NR_getpid);

	printf("pid = %d\n", pid);
	printf("pid1 = %d\n", pid1);

	printf("Current jiffies is %lx\n", ret);


	return 0;
}
