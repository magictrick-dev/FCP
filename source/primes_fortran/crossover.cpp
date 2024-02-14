#include <iostream>
#include <cstdint>

extern "C" void prime_seive(int64_t *n_size);

int
main(int argc, char ** argv)
{
    
    if (argc <= 1)
        return 0;

    int64_t n_size = std::stoi(argv[1]);
    prime_seive(&n_size);

    return 0;
}
