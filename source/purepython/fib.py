import sys


def fast_fib(n):
    farray = [1, 1]

    index = 2
    while index < n:
        farray.append(farray[index-1] + farray[index-2])
        index = index + 1
    
    return farray[index-1]

if __name__ == '__main__':
    fib_n_index = sys.argv[1]
    value = fast_fib(int(fib_n_index))
    print(value)

