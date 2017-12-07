List of all files you submitted:

Not sure if you want a full recursive ls, so I just added files I think are relevant to the assignment/grading

asst9.cpp
cvec.h
rigtform.h


Note the platform you used for development (Windows, OS X, ...):

Windows 8.1, Visual Studio 2017 Community Edition

Provide instructions on how to compile and run your code, especially if you used a nonstandard Makefile, or you are one of those hackers who insists on doing things differently.

Open in VS and run

Indicate if you met all problem set requirements (more importantly, let us know where your bugs are and what you did to try to eliminate the bugs; we want to give you as much partial credit as we can).

Hair physics works, hair bending should work. However, hair is very droopy and doesn't work well with gravity. However, without gravity it will return to it's proper place, so I'm definitely doing something right.

Provide some overview of the code design. Don't go into details; just give us the big picture.

Do normal averaging for each vertex, then do the calculations at each vertex, using the previous shell coordinate and its normal. Use the callback to step over and change tip position and velocities based on tip displacements/vels as well as gravity and resting position of the tips. Also did d calculation to try and make it bendy. Used math provided by spec here also, dividing tip displacement by sum of d's.

Let us know how to run the program; what are the hot keys, mouse button usage, and so on? Describe steps or sequences of steps the TF should take to test and evaluate your code (especially if your implmenentation strays from the assignment specification).

Same as directions.

Finally, did you implement anything above and beyond the problem set? If so, document it in order for the TFs to test it and evaluate it.

No :(
