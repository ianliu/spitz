CPPFLAGS = -I..
CFLAGS = -shared -fPIC -g3 -O0
LDFLAGS = -L.. -lspitz

all: pi.so

pi.so: pi.c
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

test: pi.so
	LD_LIBRARY_PATH=$$PWD/.. PATH=$$PATH:$$PWD/.. mpirun -np 3 spitz $$PWD/pi.so 10000

clean:
	-rm -f pi.so
