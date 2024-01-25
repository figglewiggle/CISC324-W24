1. Why is the total being returned by the program incorrect (e.g n=1, total=0, n=3, total=3 (when it should be 15))?
Well, A(y) and B(y) are computing their respective values correctly (as we checked in the print statements), so that means there is a data synchronization issue between the parent and the child process. Specifically, the parent process is only being updated with A(y), and is not piping in the data from the child process's B(y) output. 

2. How we fixed the issue: we sent the Total from the child process as an exit status to the parent process, which is stored as a 16-bit integer, where the top half includes the bits for the number 12 but it's shifted 8 bits to the left. This means that in order to get back to the standard 8-bit integer that Python has for the Total from b, you need capture the result by calling os.wait() in the parent function and then adding the exit status from the tuple shifted 8 to the right into the parent Total.




Fixing the Issue:
The issue was fixed by implementing inter-process communication (IPC) using a pipe. This allowed the child process to send its calculated sum back to the parent process. Additionally, os.wait() was used in the parent process to wait for the child process to complete before calculating the final total. This ensured that the sums calculated by both processes were correctly combined.

Limitation at Certain Value of n:
After fixing the issue, you may still find incorrect sums starting from a certain value of n. This limitation is likely due to the buffer size of the pipe used for IPC. When the sum calculated by the child process becomes too large to fit into the buffer, it cannot be correctly transmitted to the parent, leading to incorrect total sums.

Switching Functions of Parent and Child:
If you switch the functions of the parent and child processes, the value of n at which the sum becomes incorrect might change. This change depends on how the workload is distributed between the two processes and the capacity of the IPC mechanism. The new threshold value would depend on the specific implementation details and system constraints.
