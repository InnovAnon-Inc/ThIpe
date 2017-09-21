lib_LTLIBRARIES = libthipe.la libthrio.la
libthipe_la_SOURCES = buffer.c pipe.c io.c
#include_HEADERS = buffer.h pipe.h io.h
include_HEADERS = buffer.h pipe.h io.h thrio.h
#libthipe_la_LDFLAGS = -lrestart -ltscpaq -lcpaq
libthipe_la_LIBADD = -lrestart -ltscpaq -lcpaq

libthrio_la_SOURCES = thrio.c
#include_HEADERS = thrio.h
libthrio_la_LDFLAGS = -lrestart -ltscpaq -lcpaq -lpthread
#libthrio_la_LDADD = libthipe.la
libthrio_la_LIBADD = libthipe.la

AM_CPPFLAGS = -D__STDC_INT64__
