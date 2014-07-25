SRC = cfifo.c log.c main.c jobmanager.c message.c

CPPFLAGS = -I.
CFLAGS = -g3 -O0 -Wall -Wextra
LDFLAGS = -L. -lspitz -ldl -lrt

all: spitz

spitz: $(SRC) libspitz.so
	mpicc $(CFLAGS) $(CPPFLAGS) -o $@ $(SRC) $(LDFLAGS)

libspitz.so: barray.c
	gcc -shared -fPIC -Wl,-soname,$@ -o $@ $^

clean:
	-rm -f spitz libspitz.so

test:
	@true

prefix = /usr/local
libdir = $(prefix)/lib
bindir = $(prefix)/bin
incdir = $(prefix)/include

install: libspitz.so spitz
	install -m 755 -d $(libdir)
	install -m 755 -d $(bindir)
	install -m 755 -d $(incdir)/spitz
	install -m 755 libspitz.so $(libdir)
	install -m 755 spitz $(bindir)
	install -m 755 barray.h $(incdir)/spitz

.PHONY: all clean
