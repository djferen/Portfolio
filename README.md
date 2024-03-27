# Portfolio

**Purpose:**

The goals of this project are:

1. Demonstrate some of software development skills included C++, CMake, and CI/CD
2. Keep me doing something that I love doing

**General Setup Instructions:**

A C/C++ development environment with CMake and Make installed.

**Build Instructions:**

  `cmake . && make`

Run tests with:

  `make Test`

or 

  `make TestFIFO`

Note: other unit tests may be run, see the `CMakeLists.txt` file for more of them.

**General Browsing Info:**

The C++ code can be found as follows:

1. The `library` of data structures are located in the include directory.
2. The `tests` of the data structures are located in the test directory.
3. The `puzzles` (C++ coding challenges) are located in the puzzles directory.

**Data Structures Library**

The library of data structures code and test code contain the following structures:

- `node.h` contains a linked list node template structure
- `doublylinkednode.h` contains a double linked node template structure
- `stack.h` contains a pointer based stack template structure that uses node.h
- `fifo.h` contains a pointer based fifo template structure that uses doublylinkednode.h
- `sfifo.h` contains a 2-stack based fifo template structure that uses 2 stacks to implement FIFO
- `binarytreenode.h` contains a pointer based binary tree node tempate structure
- `binarytree.h` contains a pointer based binary tree tempate structure that uses binartreenode.h
