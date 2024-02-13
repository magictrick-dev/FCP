#include <cstdlib>

#if defined(__WIN32)
#   define externable extern "C" __declspec(dllexport)
#else
#   define externable extern "C"
#endif
#include <iostream>

externable int64_t
fast_fibonacci(int n_index)
{
    int64_t *fib_path = (int64_t*)malloc(sizeof(int64_t) * n_index); 
    fib_path[0] = 1;
    fib_path[1] = 1;

    int idx = 2;
    while (idx < n_index)
    {
        fib_path[idx] = fib_path[idx - 1] + fib_path[idx - 2];
        idx++;
    }

    int64_t value = fib_path[idx-1];
    free(fib_path);
    return value;

}

#if defined(USE_MAIN)
#include <iostream>

int main(int argc, char ** argv)
{
    if (argc <= 1)
        return 0;

    int n_index = std::stoi(argv[1]);
    int64_t output = fast_fibonacci(n_index);
    std::cout << "Fibonacci of n=" << n_index << " is " << output << std::endl;

    return 0;
}

#endif
