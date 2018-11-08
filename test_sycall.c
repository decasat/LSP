#include <stdio.h>
#include <linux/unistd.h>
#include <sys/syscall.h>


#define __NRgetjiffies    320
#define __NR_diffjiffies   321
#define ``NR_pdiffjiffies  322


_syscall0( long, getjiffies );
_syscall1( long, diffjiffies, long, ujiffies );
_syscall2( long, pdiffjiffies, long, ujiffies, long*, presult );


int main()
{
	  long jifs, result;
	    int err;


	      jifs = getjiffies();


	        printf( "difference is %lx\n", diffjiffies(jifs) );


		  err = pdiffjiffies( jifs, &result );


		    if (!err) {
			        printf( "difference is %lx\n", result );
				  } else {
					      printf( "error\n" );
					        }


		      return 0;
}

