gfortran -c fibonacci.f -fcray-pointer -fdefault-integer-8
g++ -c crossover.cpp -DUSE_MAIN
g++ fibonacci.o crossover.o -lgfortran -o fffib
