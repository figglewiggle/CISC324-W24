import os
import sys
import math

def A(y):
    """Computes the sum of [(y/2)+1] + [((y+1)/2)+1] + [((y+2)/2)+1] + ... [((y+k)/2)+1] + ... + y"""
    total = 0
    for i in range(int(math.floor(y/2)+1), y+1):
        total += i
        print("total B: ", total)
    return total

def B(y):
    """Computes and returns the sum of 0 + 1 + 2 + 3 + ... + k + ... + [y/2]"""
    total = 0
    for i in range(int(y/2) + 1):
        total += i
        print("total A: ", total)
    return total

def main(n = None):
    Total = 0

    # Check for the correct number of command-line arguments
    if n is None:
        print("The program needs one parameter to be executed (e.g., python_script.py 13)")
        sys.exit(0)

    x = n

    # Ensure that the parameter is greater than 0
    if x <= 0:
        print("Unvalid parameter: The parameter should be greater than 0, exiting ...")
        sys.exit(0)

    # Create a child process
    pid = os.fork()
    print("pid=", pid)

    # If the fork failed
    if pid < 0:
        print("Fork system call failed")
        return

    if pid != 0:  # Parent process
        Total += A(x)
        result = os.wait()
        print("result: ", result)
        Total+=result[1] >> 8
        print("result after right shift: ", result[1] >> 8)
        print("Total after A: ", Total)
    else:  # Child process
        Total += B(x)
        print("Total after B: ", Total)
        os._exit(Total)  # Ensure the child process terminates here

    # If this is the parent process, print the total summation
    if pid != 0:
        print(f"The total is: {Total}")

if __name__ == "__main__":
    n = 45
    main(n)
