LIBBUFFER_LIBADD =

include $(top_srcdir)/restart/src/Makefile-LIBADD.inc
LIBPIPE_LIBADD  = ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)
include $(top_srcdir)/TSCPAQ/src/Makefile-LIBADD.inc
LIBPIPE_LIBADD += ../TSCPAQ/src/.libs/libtscpaq.la $(LIBTSCPAQ_LIBADD)
LIBPIPE_LIBADD += libbuffer.la $(LIBBUFFER_LIBADD)

LIBIO_LIBADD =
#LIBIO_LIBADD += ../TSCPAQ/src/.libs/libtscpaq.la $(LIBTSCPAQ_LIBADD)
LIBIO_LIBADD += libbuffer.la $(LIBBUFFER_LIBADD)
LIBIO_LIBADD += libpipe.la $(LIBPIPE_LIBADD)

LIBTHIPE_LIBADD  = libio.la $(LIBIO_LIBADD)
#LIBTHIPE_LIBADD += libpipe.la $(LIBPIPE_LIBADD)
#LIBTHIPE_LIBADD += libbuffer.la $(LIBBUFFER_LIBADD)
