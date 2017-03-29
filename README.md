# Portfolio

Purpose:

The goals of this project are:

1. Demonstrated some of my C++ skills
2. Keep my skills sharp
3. Help me get a job.


Introduction:

1. I've developed the cmake file to make build and test easy:

	CMakeLists.txt  

2. The library of code (the bulk of the code) is in the include directory.


3. I've added a number of puzzles that I've recently completed in the puzzles directory.


Build Instructions:

  cmake .

  make

Run tests with:

  make Test

or 

  make TestFIFO 

etc.


Further Info:

There is library and test code for the following areas:

node.h contains a linked list node template structure

doublylinkednode.h contains a double linked node template structure

stack.h contains a pointer based stack template structure that uses node.h

fifo.h contains a pointer based fifo template structure that uses doublylinkednode.h

binarytreenode.h contains a pointer based binary tree node tempate structure

binarytree.h contains a pointer based binary tree tempate structure that uses binartreenode.h

