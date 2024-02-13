#if defined(__WIN32)
#   define externable extern "C" __declspec(dllexport)
#else
#   define externable extern "C"
#endif
#include <cstdint>

extern "C" void fast_fibonacci(int64_t *n_index_in, int64_t *fib_value_out);

externable int64_t
fortran_fast_fibonacci(int64_t n_index)
{

    int64_t value_out = 0;
    fast_fibonacci(&n_index, &value_out);
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
    int64_t value = fortran_fast_fibonacci(n_size);
    std::cout << "Output: " << value << std::endl;

    return 0;
}

#endif

