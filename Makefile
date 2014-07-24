SRC = cfifo.c log.c spitz.c jobmanager.c message.c

CPPFLAGS = -I.
CFLAGS = -g3 -O0 -Wall -Wextra
LDFLAGS = -L. -lspitz -ldl -lrt

all: spitz examples

spitz: $(SRC) libspitz.so
	mpicc $(CFLAGS) $(CPPFLAGS) -o $@ $(SRC) $(LDFLAGS)

libspitz.so: barray.c
	gcc -shared -fPIC -Wl,-soname,$@ -o $@ $^

examples:
	$(MAKE) -C examples

test: spitz
	$(MAKE) -C examples $@

clean:
	-rm -f spitz libspitz.so
	$(MAKE) -C examples $@

prefix = /usr/local
libdir = $(prefix)/lib
bindir = $(prefix)/bin

install: libspitz.so spitz
	install -m 755 -d $(libdir)
	install -m 755 -d $(bindir)
	install -m 755 libspitz.so $(libdir)
	install -m 755 spitz $(bindir)

.PHONY: all clean examples
