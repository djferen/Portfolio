# Portfolio

**Purpose**

This `Portfolio` project contains a simple, extensible library creation and test infrastructure pattern.  This project functions as a library creation tool in that a new C++ library may be created and tested when the following is added:
1. a *.h file in the include directory for adding library code
2. a test*.cpp file in the test directory to test the library code
3. update the `CMakeLists.txt` file to define its build and test target configurations

**Environments:**

This supports Github Action code for building and testing on github.com and running the same Github action code locally with [act](https://github.com/nektos/act) so this can be developed and tested locally.

**General Setup Instructions:**

A C/C++ development environment with `CMake`, `C++` compiler, `Make` and `gtest`, etc. are all needed to be installed.

Install prerequisites with: `make install-prerequisites`

**C++ Lint Instructions:**

C++ format maintenance is made easy by using tools:

1. Run the format checker: `make check-format`
2. Run the auto-formatter: `make format`

**Build Instructions:**

  `make build`

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

**Data Structures Library:**

The library of data structures code and test code contain the following structures:

- `node.h` contains a linked list node template structure
- `doublylinkednode.h` contains a double linked node template structure
- `stack.h` contains a pointer based stack template structure that uses node.h
- `fifo.h` contains a pointer based fifo template structure that uses doublylinkednode.h
- `sfifo.h` contains a 2-stack based fifo template structure that uses 2 stacks to implement FIFO
- `binarytreenode.h` contains a pointer based binary tree node tempate structure
- `binarytree.h` contains a pointer based binary tree tempate structure that uses binartreenode.h
