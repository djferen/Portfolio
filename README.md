# Portfolio

**Purpose**

This `Portfolio` contains a variety of applications written in the following languages: C++ (mostly), Python (some), and Rust (little).  Also cotained herein are build files found in CMake, Makefile, and Docker Compose in support of this project.

**Virtualization for Build and Test**

The [Dockerfile](Dockerfile) was developed to create a build and test environment for the C++ code detailed below.

Additionally, a Docker Compose file [docker-compose.yml](docker-compose.yml) was developed to support the build and test use cases, etc.

Run:

  `docker compose run build-latest`
  `docker compose run test-latest`

**Direct Installation of Build Dependencies**

Warning: This command will modify your environment by installing sofware so it is recommended you do this in a virtual environment!

Install prerequisites with: `make install-prerequisites`

**C++ Lint Instructions:**

C++ format maintenance is made easy by using tools:

1. Run the format checker: `make check-format`
2. Run the auto-formatter: `make format`

**Build Instructions:**

  `make build`

Run tests with:

  `make test`

Run clean up with:

  `make clean`

Note: other unit tests may be run, see the `CMakeLists.txt` file for more of them.

**General Browsing Info:**

The C++ code can be found as follows:

1. Some `puzzles` (C++ coding challenges) are located in the `puzzles` directory.
2. The `library` of data structures are located in the `include` directory.
2. The `tests` of the data structures are located in the `test` directory.

The library of C++ data structures code and test code are contained in the following files:

* [binarytree](include/binarytree.h)
* [binarytreenode.h](include/binarytreenode.h)
* [dijkstra.h](include/dijkstra.h)
* [doublylinkednode.h](include/doublylinkednode.h)
* [fifo.h](include/fifo.h)
* [filesystem.h](include/filesystem.h)
* [hashmap.h](include/hashmap.h)
* [keypad.h](include/keypad.h)
* [linkedlist.h](include/linkedlist.h)
* [minheap.h](include/minheap.h)
* [node.h](include/node.h)
* [poly.h](include/poly.h)
* [sfifo.h](include/sfifo.h)
* [stack.h](include/stack.h)

**Cloud CI Environment**

There is support for Github Action code for building and testing on github.com and running the same Github action code in the Github cloud enviroments, see [Github Workflow](.github/workflows/cmake-single-platform.yml).

**Local CI Environment**

There is support for Github Action code for building and testing on github.com and running the same Github action code locally with [act](https://github.com/nektos/act).

**Implementation Note**

The C++ portion of this `Portfolio` project contains a simple, extensible library creation and test infrastructure pattern.  This project functions as a library creation tool in that a new C++ library may be created and tested when the following is added:
1. a *.h file in the `include` directory for adding library code
2. a test*.cpp file in the `test` directory to test the library code
3. update the `CMakeLists.txt` file to define its build and test target configurations
