lib_LTLIBRARIES = libthipe.la
libthipe_la_SOURCES = buffer.c pipe.c io.c
include_HEADERS = buffer.h pipe.h io.h
libthipe_la_LIBADD = -lrestart -ltscpaq -lcpaq

#bin_PROGRAMS = thrio
#thrio_SOURCES = main.c
#thrio_LDADD = libthipe.la libthrio.la -lrestart -ltscpaq -lcpaq -lpthread

AM_CPPFLAGS += -D__STDC_INT64__
