#include <cstdlib>

#if defined(__WIN32)
#   define externable extern "C" __declspec(dllexport)
#else
#   define externable extern "C"
#endif

externable int
fast_fibonnaci(int n_index)
{

    int *fib_path = (int*)malloc(sizeof(int) * n_index); 
    fib_path[0] = 1;
    fib_path[1] = 1;

    int idx = 2;
    while (idx < n_index)
    {
        fib_path[idx] = fib_path[idx - 1] + fib_path[idx - 2];
        idx++;
    }

    return fib_path[idx];

}

