
import threading
import time
import random

# Constants for the simulation
PHILOSOPHERS_COUNT = 5  # Defines the number of philosophers (and thus forks)
thinking_time = 1  # Maximum time a philosopher can spend thinking
eating_time = 5  # Maximum time a philosopher can spend eating

# Initialize semaphores for each fork. This setup is essential for Task 1, where each fork is represented
# by a semaphore to manage access, simulating that only one philosopher can use a fork at any given time.
# Task 1: The initial setup of the problem, including creating philosophers and forks (semaphores).
forks = [threading.Semaphore(1) for _ in range(PHILOSOPHERS_COUNT)]

def philosopher(id):
    while True:
        # Think
        print(f"Philosopher {id} is thinking.")
        time.sleep(random.randint(1, thinking_time))  # Simulates the thinking process

        # Determine the left and right fork based on the philosopher's id.
        # This logic ensures that the philosopher tries to pick up the forks adjacent to them.
        left_fork = id
        right_fork = (id + 1) % PHILOSOPHERS_COUNT

        # Task 2 starts here: Implementing a solution to prevent deadlock.
        # To avoid deadlock, a philosopher will pick up the lower-numbered fork first,
        # ensuring that the last philosopher will wait if the first fork is not available.
        # This strategy breaks the cycle that could lead to a deadlock.

        # Pick up the lower-numbered fork first
        first_fork, second_fork = sorted([left_fork, right_fork])
        forks[first_fork].acquire()  # Attempt to acquire the first fork
        print(f"Philosopher {id} picked up fork {first_fork}.")

        time.sleep(0.1)  # Added to increase the chance of deadlock for demonstration purposes

        forks[second_fork].acquire()  # Attempt to acquire the second fork
        print(f"Philosopher {id} picked up fork {second_fork}.")

        # Eat
        print(f"Philosopher {id} is eating.")
        time.sleep(random.randint(1, eating_time))  # Simulates the eating process

        # After eating, the philosopher puts down both forks.
        forks[first_fork].release()
        print(f"Philosopher {id} put down fork {first_fork}.")
        forks[second_fork].release()
        print(f"Philosopher {id} put down fork {second_fork}.")

        # After putting down the forks, the philosopher goes back to thinking, and the cycle repeats.
        # This loop is infinite, reflecting the continuous cycle of think-eat-think in the philosopher's life.

# The main part of the script that starts the threads (philosophers)
# Task 1 also includes the creation and starting of philosopher threads to simulate the problem scenario.
if __name__ == "__main__":
    # Create a thread for each philosopher
    philosophers = [threading.Thread(target=philosopher, args=(i,)) for i in range(PHILOSOPHERS_COUNT)]
    for p in philosophers:
        p.start()

    # In the provided boilerplate, philosophers are left to run indefinitely, and no joining is performed.
    # This simulates an ongoing scenario where philosophers continuously engage in their cycle of thinking and eating.
