import sys
import ctypes

def main():

    # Check for correct arguments.
    if len(sys.argv) <= 1:
        print("Please provide a value of n to calculate fibonacci sequence.")
        exit()
    
    # Load the library.
    fortrancpp = ctypes.CDLL("./source/fortrancpp/fcffib.so")
    fortrancpp.fortran_fast_fibonacci.restype = ctypes.c_longlong

    # Invoke the fibonacci function.
    value = fortrancpp.fortran_fast_fibonacci(int(sys.argv[1]))
    print(value)
    

if __name__ == "__main__":
    main()

