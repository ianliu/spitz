CPPFLAGS = -I..
CFLAGS = -shared -fPIC -g3 -O0
LDFLAGS = -L../spitz -lspitz

all: pi.so

pi.so: pi.c
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

test: pi.so
	# Set some environment variables
	LD_LIBRARY_PATH=$$PWD/../spitz PATH=$$PATH:$$PWD/../spitz \
			mpirun -np 3 spitz $$PWD/pi.so 10000

clean:
	-rm -f pi.so
