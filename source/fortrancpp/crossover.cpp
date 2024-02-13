#if defined(__WIN32)
#   define externable extern "C" __declspec(dllexport)
#else
#   define externable extern "C"
#endif

extern "C" void fast_fibonacci_(int *n_index_in, int *fib_value_out);

externable int
fortran_fast_fibonacci(int n_index)
{

    int value_out = 0;
    fast_fibonacci_(&n_index, &value_out);
    return value_out;

}

#if defined(USE_MAIN)
#include <cstdlib>
#include <iostream>
int main(int argc, char ** argv)
{
    if (argc <= 1)
        return 0;

    int n_size = std::stoi(argv[1]);
    int value = fortran_fast_fibonacci(n_size);
    std::cout << "Output: " << value << std::endl;

    return 0;
}

#endif

