Undefined Behavior Generation in So-bogus and GCC 5.3
=====================================================

Simple self-contained example that generates undefined behavior warnings with 
GCC 5.3's undefined behavior sanitizer and So-bogus. 

After cloning the repository build and run the code with the following commands:

    mkdir build
    cd build
    CC=gcc-5 CXX=g++-5 cmake ..
    make
    ./undefined_trigger/undefined_trigger

I observe the following error:

    gcc/5.3.0/include/c++/5.3.0/bits/stl_vector.h:795:46: runtime error: reference binding to null pointer of type 'const value_type'
