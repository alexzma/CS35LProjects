When making the multithreaded version of the program, I ran into several issues.

First, I had trouble placing all the needed information into the threads.
I had to make sure that all the variables not initialized in the loop in the 
single threaded version were transferred into the function used for the threads.
I missed several variables in my initial version of the multi-threaded program,
so I had to change my input struct to make sure the input was adequate.

Also, the Vec3 type can not be copied into a struct and then copied as an 
initializing value. Fortunately, the Vec3 variables were constant, so I could 
set them manually.

When setting the values of the inputs to the threads, I had trouble making sure
 that each thread went through the correct pixels. I had to adjust the numbers 
several times to make sure that the pixels were distributed evenly and separately.

When placing the single threaded loop into the function, I had to allocate 
memory to hold the output, since writing from the threads to stdout would cause
 the values to be out of order. Therefore, I stored the values in a character 
array, and returned the array.

For some reason, I had to use a triple pointer to interpret the character array
correctly, but that was just something I had to do to make the program work.

Also, I initially reallocated memory whenever I put a new character into my 
array, but then I realized that since I knew the number of pixels and the 
approximate number of characters per pixel, I could allocate the memory all at 
once at the beginning of the function.

In terms of time, my implementation of SRT with one thread is probably slightly
 slower than the original version of SRT, because my code uses extra variables 
and checks compared to the original version.
However, my implementation of SRT is much faster if there are multiple threads.
When I ran the "make clean check" command on the Makefile, the times were:
1 Thread:
real time: 43.492 seconds
user time: 43.486 seconds
system time: 0.001 seconds

2 Threads:
real time: 22.059 seconds
user time: 44.857 seconds
system time: 0.003 seconds

4 Threads:
real time: 14.894 seconds
user time: 44.832 seconds
system time: 0.004 seconds

8 Threads:
real time: 9.310 seconds
user time: 44.720 seconds
system time: 0.004 seconds

As the number of threads increased, the real time of the program decreased 
proportionally to the number of threads, though the gain becomes less than prop
ortional with more threads. The user time increased slightly with more threads,
 and system time increased slightly.
Multithreading significantly increased the speed of the program, due to 
multiple pixels being processed at the same time rather than one at a time.
