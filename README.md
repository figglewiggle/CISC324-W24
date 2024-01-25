1. Why is the total being returned by the program incorrect (e.g n=1, total=0, n=3, total=3 (when it should be 15))?
Well, A(y) and B(y) are computing their respective values correctly (as we checked in the print statements), so that means there is a data synchronization issue between the parent and the child process. Specifically, the parent process is only being updated with A(y), and is not piping in the data from the child process's B(y) output. 

2. How we fixed the issue: we sent the Total from the child process as an exit status to the parent process, which is stored as a 16-bit integer, where the top half includes the bits for the number 12 but it's shifted 8 bits to the left. This means that in order to get back to the standard 8-bit integer that Python has for the Total from b, you need capture the result by calling os.wait() in the parent function and then adding the exit status from the tuple shifted 8 to the right into the parent Total.

3. What is the "n" that makes the Total incorrect? 
We found that "n" to be 26, since when we put in 26, the total for B ended up being 260, and when it is shifted to the left by 8 to be put into the 16 bit exit status, the value becomes greater than 2^16, so the value stored in the exit status is truncated. Then, when it is converted back to an 8-bit integer format (4 byte), the truncated number is what is converted, and not the correct one.

4. What is the "n" that makes Total incorrect after switching A and B?
The "n" that makes this happen is 46, since A is done in the child process, so when the total return by A is above 2^8, when it is shifted to the left to fit into the 16-bit exit status, the value goes above 2^16, same as the previous question. The only difference in this one is the limit for "n" has increased since B is no longer being passed through the exit status and A is instead which grows slower than B. 
