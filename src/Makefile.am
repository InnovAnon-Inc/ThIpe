AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libbuffer.la
include_HEADERS += buffer.h
libbuffer_la_CPPFLAGS = $(GLITTER_CFLAGS)
libbuffer_la_LIBADD   = $(GLITTER_LIBS)

lib_LTLIBRARIES += libpipe.la
include_HEADERS += pipe.h
libpipe_la_CPPFLAGS =          $(GLITTER_CFLAGS) $(TSCPAQ_CFLAGS) $(RESTART_CFLAGS)
libpipe_la_LIBADD   = -lbuffer $(GLITTER_LIB)    $(TSCPAQ_LIBS)   $(RESTART_LIBS)
EXTRA_libpipe_la_DEPENDENCIES = libbuffer.la

lib_LTLIBRARIES += libio.la
include_HEADERS += io.h
libio_la_CPPFLAGS =                 $(GLITTER_CFLAGS) $(TSCPAQ_CFLAGS) $(RESTART_CFLAGS)
libio_la_LIBADD   = -lpipe -lbuffer $(GLITTER_LIBS)   $(TSCPAQ_LIBS)   $(RESTART_LIBS)
EXTRA_libio_la_DEPENDENCIES = libpipe.la

lib_LTLIBRARIES += libthipe.la
libthipe_la_SOURCES =
libthipe_la_CPPFLAGS =                      $(GLITTER_CFLAGS) $(TSCPAQ_CFLAGS) $(RESTART_CFLAGS)
libthipe_la_LIBADD   = -lio -lpipe -lbuffer $(GLITTER_LIBS)   $(TSCPAQ_LIBS)   $(RESTART_LIBS)
EXTRA_libthipe_la_DEPENDENCIES = libio.la

#Bin_PROGRAMS += thipe-test
#thipe_test_LDADD = libthipe.la $(LIBTHIPE_LIBADD)

