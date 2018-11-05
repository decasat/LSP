/********************************************************************\
 *	Filename: lab07_writev4.c
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



int
main (int argc, char *argv[])
{
  int fd;
  struct iovec *vec;
  struct iovec *vec_next;
  int i;
  char newline = '\n';
  char *filename = argv[1];

  printf("%d arguments are passed\n", argc);
  argc -= 2;
  argv += 2;
  vec = (struct iovec *) malloc (2 * argc * sizeof (struct iovec));
  vec_next = vec;
  for (i = 0; i < argc; ++i)
    {
      vec_next->iov_base = argv[i];
      vec_next->iov_len = strlen (argv[i]);
      ++vec_next;
      vec_next->iov_base = &newline;
      vec_next->iov_len = 1;
      ++vec_next;
    }
  fd = open (filename, O_RDWR | O_CREAT, 0666);
  writev (fd, vec, 2 * argc);

  close (fd);
  free (vec);
  return 0;

}
