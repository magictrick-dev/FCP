gfortran -c fibonacci.f -fcray-pointer -fdefault-integer-8
g++ -c crossover.cpp
g++ -shared fibonacci.o crossover.o -lgfortran -o fcffib.so
