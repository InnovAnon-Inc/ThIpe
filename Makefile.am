# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libbuffer.pc src/libio.pc src/libpipe.pc src/libthipe.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libbuffer.pc.in src/libio.pc.in src/libpipe.pc.in src/libthipe.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

