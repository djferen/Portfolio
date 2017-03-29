cmake_minimum_required (VERSION 3.5)
project (portfolio)
SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
add_executable(test-node test-node.cpp)
add_executable(test-stack test-stack.cpp)
add_executable(test-fifo test-fifo.cpp)
add_executable(test-doublylinkednode test-doublylinkednode.cpp)
add_executable(test-binarytree test-binarytree.cpp)
add_executable(test-binarytreenode test-binarytreenode.cpp)
add_executable(test-dijkstra test-dijkstra.cpp)
add_executable(test-roman roman.cpp)
add_executable(test-getlongestword getlongestword.cpp)

