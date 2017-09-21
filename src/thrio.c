#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <strings.h>

#include <pthread.h>

#include <io.h>

#include <thrio.h>

typedef struct {
   io_t *restrict io;
   fd_t in, out;
} io_thread_cb_t;

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
static void *io_thread_cb (void *restrict _arg) {
   io_thread_cb_t *restrict arg = (io_thread_cb_t *restrict) _arg;
   error_check (rw_io (arg->io, arg->in, arg->out) != 0) return NULL;
   return NULL;
}

TODO (this macro has been moved to glitter.h)
#ifndef min
#define min(A, B) ((A) < (B) ? (A) : (B))
#endif

typedef struct {
   io_t *restrict io;
   thrio_cb_t cb;
} worker_thread_cb_t;

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
static int worker_thread_cb_cb (
   buffer_t *restrict buf_out,
   buffer_t const *restrict buf_in,
   void *restrict _arg) {
   thrio_cb_t *restrict arg = (thrio_cb_t *restrict) _arg;

   TODO (init buf_out->n to out_bufsz below)
   error_check (*arg (buf_out->buf, buf_in->buf,
      buf_in->n, &(buf_out->n)) != 0)
      return -1;
   return 0;
}

__attribute__ ((nonnull (1), nothrow, warn_unused_result))
static void *worker_thread_cb (void *restrict _arg) {
   /*io_t *restrict arg = (io_t *restrict) _arg;*/
   worker_thread_cb_t *restrict arg =
      (worker_thread_cb_t *restrict) _arg;
   error_check (worker_io (arg->io, worker_thread_cb_cb, &(arg->cb)) != 0)
      return NULL;
   return NULL;
}

__attribute__ ((nonnull (7), nothrow, warn_unused_result))
int thrio (
   fd_t in, fd_t out,
   size_t in_bufsz, size_t in_nbuf,
   size_t out_bufsz, size_t out_nbuf,
   thrio_cb_t cb) {
   io_t dest/*, src*/;
   io_thread_cb_t io_thread_cb_arg;
   worker_thread_cb_t worker_thread_cb_arg;
   pthread_t io_thread;
   pthread_t worker_thread;
   buffer_t *restrict buf_in;
   buffer_t *restrict buf_out;
   error_check (alloc_io (&dest, /*&src,*/
      in_bufsz, in_nbuf, out_bufsz, out_nbuf) != 0) return -1;

   io_thread_cb_arg.io = &dest;
   io_thread_cb_arg.in  = in;
   io_thread_cb_arg.out = out;
   error_check (pthread_create (&io_thread, NULL, io_thread_cb, &dest) != 0) {
      free_io (&dest);
      return -2;
   }
   worker_thread_cb_arg.io = &dest;
   worker_thread_cb_arg.cb = cb;
   error_check (pthread_create (&worker_thread, NULL, worker_thread_cb, /*&src*/ /*&dest*/ &worker_thread_cb_arg) != 0) {
      TODO (kill io thread)
      free_io (&dest);
      return -3;
   }

   error_check (pthread_join (io_thread, NULL) != 0) {
      TODO (kill worker thread)
      free_io (&dest);
      return -4;
   }
   error_check (pthread_join (worker_thread, NULL) != 0) {
      free_io (&dest);
      return -5;
   }

   error_check (free_io (&dest/*, &src*/) != 0) return -6;

   return 0;
}
