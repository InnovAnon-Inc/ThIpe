#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdlib.h>

#include <pipe.h>

__attribute__ ((leaf, nonnull (1, 2, 3/*, 4*/), nothrow))
void init_io (
   io_t *restrict io_in,
   /*io_t *restrict io_out,*/
   pipe_t *restrict in,
   pipe_t *restrict out) {
   io_in->in  = in;
   io_in->out = out;
   /*io_out->in  = out;
   io_out->out = in;*/
}

__attribute__ ((nonnull (1/*, 2*/), nothrow, warn_unused_result))
int alloc_io (
   io_t *restrict dest,
   /*io_t *restrict src,*/
   size_t in_bufsz,  size_t in_nbuf,
   size_t out_bufsz, size_t out_nbuf) {
   pipe_t *restrict in;
   pipe_t *restrict out;

   in  = malloc (sizeof (pipe_t));
   error_check (in == NULL) return -1;
   out = malloc (sizeof (pipe_t));
   error_check (out == NULL) {
      free (in);
      return -2;
   }

   init_io (dest, /*src,*/ in, out);

   error_check (alloc_pipe (in, in_bufsz, in_nbuf) != 0) {
      free (out);
      free (in);
      return -3;
   }
   error_check (alloc_pipe (out, out_bufsz, out_nbuf) != 0) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      (void) free_pipe (in);
	#pragma GCC diagnostic pop
      free (out);
      free (in);
      return -4;
   }

   return 0;
}

__attribute__ ((leaf, nonnull (1/*, 2*/), nothrow, warn_unused_result))
int free_io (io_t *restrict dest/*, io_t *restrict src*/) {
   error_check (free_pipe (dest->in) != 0) return -1;
   error_check (free_pipe (dest->out) != 0) return -2;
   free (dest->in);
   free (dest->out);
   return 0;
}
