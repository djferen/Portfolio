cmake_minimum_required (VERSION 3.5)

project (portfolio)
include_directories(include)
file(MAKE_DIRECTORY build)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

add_executable(test-node test/test-node.cpp)
add_executable(test-stack test/test-stack.cpp)
add_executable(test-fifo test/test-fifo.cpp)
add_executable(test-doublylinkednode test/test-doublylinkednode.cpp)
add_executable(test-binarytreenode test/test-binarytreenode.cpp)
add_executable(test-binarytree test/test-binarytree.cpp)
add_executable(test-dijkstra test/test-dijkstra.cpp)
add_executable(test-roman puzzles/roman.cpp)
add_executable(test-getlongestword puzzles/getlongestword.cpp)
add_executable(test-lettercapitalize puzzles/lettercapitalize.cpp)
add_executable(test-matchsymbols puzzles/matchsymbols.cpp)
add_executable(test-timeconvert puzzles/timeconvert.cpp)

add_custom_target(TestNode test-node
                  DEPENDS test-node)
add_custom_target(TestStack test-stack
                  DEPENDS test-stack)
add_custom_target(TestFIFO test-fifo
                  DEPENDS test-fifo)
add_custom_target(TestDLL test-doublylinkednode
                  DEPENDS test-doublylinkednode)
add_custom_target(TestBTN test-binarytreenode
                  DEPENDS test-binarytreenode)
add_custom_target(TestBT test-binarytree
                  DEPENDS test-binarytree)
add_custom_target(TestD test-dijkstra
                  DEPENDS test-dijkstra)
add_custom_target(TestR test-roman
                  DEPENDS test-roman)
add_custom_target(TestGLW test-getlongestword
                  DEPENDS test-getlongestword)
add_custom_target(TestLC test-lettercapitalize
                  DEPENDS test-lettercapitalize)
add_custom_target(TestMS test-matchsymbols
                  DEPENDS test-matchsymbols)
add_custom_target(TestTC test-timeconvert
                  DEPENDS test-timeconvert)

add_custom_target(Test
                  DEPENDS TestNode TestStack TestFIFO TestDLL TestBTN TestD TestR TestGLW TestLC TestMS TestTC)
