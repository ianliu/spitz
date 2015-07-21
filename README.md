# SPITZ

SPITZ is a reference implementation of the parallel programing model
SPITS (Scalable Partially Idempotent Tasks System). This allows you to
implement parallel programs that will scale in big heterogeneous
clusters and offer fault tolerance.

This is achieved by a C API where you only need to implement the
important functions for your problem, hiding the complexity of load
balancing, fault tolerance, task distribution, etc.

## Prerequisites

To compile SPITZ you need the following programs:

 * C and C++ compiler
 * Make
 * MPI

For Ubuntu/Debian:

    apt-get install make gcc g++ openmpi-bin libopenmpi-dev

For CentOS/Redhat:

    yum install make gcc gcc-c++ openmpi openmpi-devel

For Arch Linux:

    pacman -S make gcc openmpi

## Compiling

SPITZ uses CMake as a building platform. To compile issue the following
commands:

    mkdir build
    cd build
    cmake ..
    make

## Examples

There is a very simple example that calculates pi using Monte-Carlo
algorithm in the directory _examples_. To run the test, execute

    cd build/examples
    make test-pi-c test-pi-cpp

Take a look at `examples/pi.c` to see how it was implemented. You might
also want to read `examples/CMakeLists.txt` to understand the build
process.

## System wide installation

To install SPITZ in the default directory (/usr/local) issue the
following command:

    cd build
    make install

If you want to change the prefix directory, issue:

    cd build
    cmake -DCMAKE_INSTALL_PREFIX=/usr
    make install

## Troubleshooting

### mpirun was unable to find the specified executable file

If you are getting this MPI error message it means the SPITZ binary
isn't in your `PATH`. You probably need to set the `PATH` environment
variable to point to the correct location like so:

    export PATH=$PATH:/path/to/install/dir/bin

### error while loading shared libraries: libspitz.so

This probably means that `libspitz.so` was installed in a unusual place,
so you need to set the `LD_LIBRARY_PATH` environment variable to point
to the installation directory like so:

    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/install/dir/lib

# Reporting bugs

If you find any bug you may report an issue in the github repository
here: [github.com/ianliu/spitz/issues](github.com/ianliu/spitz/issues).
We will be very happy to fix them!

<!-- vim:tw=72:sw=4:et:sta:spell
-->
