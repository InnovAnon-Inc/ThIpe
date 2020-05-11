AC_INIT([libthipe], [0.0], [laurence.a.maddox@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])
#AC_CONFIG_SUBDIRS([glitter restart TSCPAQ])

AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([glitter.h restart.h tscpaq.h])
AC_CHECK_HEADERS([pthread.h])

AC_CHECK_LIB([stdlib],[malloc,free])
AC_CHECK_LIB([restart],[r_read,r_write])
AC_CHECK_LIB([tscpaq],[tscpaq_alloc_queue,tscpaq_free_queue])
AC_CHECK_LIB([tscpaq],[tscpaq_enqueue,tscpaq_dequeue])
AC_CHECK_LIB([pthread],[pthread_create,pthread_join])

LIBBUFFER_LIBADD="`PATH=src:$PATH libbuffer_config --libs`"
AC_SUBST(LIBBUFFER_LIBADD)

LIBPIPE_LIBADD="libbuffer.la `PATH=src:$PATH libpipe_config --libs`"
#LIBPIPE_LIBADD="`PATH=src:$PATH libpipe_config --libs`"
AC_SUBST(LIBPIPE_LIBADD)

LIBIO_LIBADD="libpipe.la `PATH=src:$PATH libio_config --libs`"
#LIBIO_LIBADD="`PATH=src:$PATH libio_config --libs`"
AC_SUBST(LIBIO_LIBADD)

LIBTHIPE_LIBADD="libio.la `PATH=src:$PATH libthipe_config --libs`"
#LIBTHIPE_LIBADD="`PATH=src:$PATH libthipe_config --libs`"
AC_SUBST(LIBTHIPE_LIBADD)

INNOVANON_WARNINGS([])

AC_OUTPUT
