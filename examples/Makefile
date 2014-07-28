CPPFLAGS = -I..
CFLAGS = -shared -Wall -Wextra -fPIC -g3 -O0
LDFLAGS = -L../spitz -lspitz

all: pi.so picpp.so

pi.so: pi.c
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

picpp.so: pi.cpp
	g++ $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

test: pi.so picpp.so
	# Set some environment variables
	LD_LIBRARY_PATH=$$PWD/../spitz PATH=$$PATH:$$PWD/../spitz \
			mpirun -np 3 spitz $$PWD/pi.so 10000
	LD_LIBRARY_PATH=$$PWD/../spitz PATH=$$PATH:$$PWD/../spitz \
			mpirun -np 3 spitz $$PWD/picpp.so 10000

clean:
	-rm -f pi.so picpp.so
