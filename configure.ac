AC_INIT([libthipe], [1.0], [InnovAnon-Inc@protonmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/libbuffer.pc
 src/libio.pc
 src/libpipe.pc
 src/libthipe.pc
])

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h])
#AC_CHECK_HEADERS([glitter.h restart.h tscpaq.h])
AC_CHECK_HEADERS([pthread.h])

AC_CHECK_LIB([stdlib],[malloc,free])
#AC_CHECK_LIB([restart],[r_read,r_write])
#AC_CHECK_LIB([tscpaq],[tscpaq_alloc_queue,tscpaq_free_queue])
#AC_CHECK_LIB([tscpaq],[tscpaq_enqueue,tscpaq_dequeue])
AC_CHECK_LIB([pthread],[pthread_create,pthread_join])

PKG_CHECK_MODULES([GLITTER],[glitter],,)
PKG_CHECK_MODULES([TSCPAQ],[libtscpaq],,)
PKG_CHECK_MODULES([RESTART],[librestart],,)

INNOVANON_WARNINGS([])

AC_OUTPUT

