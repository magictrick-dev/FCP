#include <iostream>
#include <cstdlib>
#include <cmath>

void
prime_seive(int limit)
{

    bool *prime_bucket = (bool *)malloc(sizeof(bool) * limit + 1);
    for (size_t idx = 0; idx < limit; ++idx)
        prime_bucket[idx] = true;
    prime_bucket[0] = false; // 0 is not a number, lol.
    prime_bucket[1] = false; // 1 is not prime.

    // Only need to go so high.
    size_t sq_limit = (size_t)std::sqrt(limit);

    // Sieve that stuff.
    for (size_t idx = 2; idx < sq_limit; ++idx)
    {

        if (prime_bucket[idx] == true)
        {

            size_t nn = idx * idx;
            size_t ni = 0;
            size_t p = nn + (ni * idx);

            while (p < limit)
            {
                prime_bucket[p] = false;
                ni++;
                p = nn + (ni * idx);
            }

        }

    }

    for (size_t idx = 0; idx < limit + 1; ++idx)
    {
        if (prime_bucket[idx] == true)
            std::cout << idx << std::endl;
    }

}

int
main(int argc, char **argv)
{
    if (argc <= 1)
        return 0;

    prime_seive(std::stoi(argv[1]));
    return 0;
}
