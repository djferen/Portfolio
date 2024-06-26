cmake_minimum_required (VERSION 3.5)

project (portfolio)
include_directories(include)
file(MAKE_DIRECTORY build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(test-node test/test-node.cpp)
add_executable(test-stack test/test-stack.cpp)
add_executable(test-fifo test/test-fifo.cpp)
add_executable(test-sfifo test/test-sfifo.cpp)
add_executable(test-doublylinkednode test/test-doublylinkednode.cpp)
add_executable(test-binarytreenode test/test-binarytreenode.cpp)
add_executable(test-binarytree test/test-binarytree.cpp)
add_executable(test-dijkstra test/test-dijkstra.cpp)
add_executable(test-minheap test/test-minheap.cpp)
add_executable(test-poly test/test-poly.cpp)
add_executable(test-filesystem test/test-filesystem.cpp)
add_executable(test-roman puzzles/roman.cpp)
add_executable(test-getlongestword puzzles/getlongestword.cpp)
add_executable(test-lettercapitalize puzzles/lettercapitalize.cpp)
add_executable(test-matchsymbols puzzles/matchsymbols.cpp)
add_executable(test-timeconvert puzzles/timeconvert.cpp)
add_executable(test-alphabetsoup puzzles/alphabetsoup.cpp)
add_executable(test-hash puzzles/hash.cpp)
add_executable(test-balancebraces puzzles/balancebraces.cpp)
add_executable(test-queue puzzles/queue.cpp)
add_executable(test-hascycle puzzles/hascycle.cpp)
add_executable(test-fibonacci puzzles/fibonacci.cpp)
add_executable(test-atomics puzzles/atomics.cpp)
add_executable(test-keypad test/test-keypad.cpp)
target_link_libraries(test-atomics Threads::Threads)

add_executable(test-linkedlist test/test-linkedlist.cpp)
target_compile_options(test-linkedlist PRIVATE -fno-elide-constructors)

add_custom_target(TestNode test-node
                  DEPENDS test-node)
add_custom_target(TestStack test-stack
                  DEPENDS test-stack)
add_custom_target(TestFIFO test-fifo
                  DEPENDS test-fifo)
add_custom_target(TestSFIFO test-sfifo
                  DEPENDS test-sfifo)
add_custom_target(TestDLL test-doublylinkednode
                  DEPENDS test-doublylinkednode)
add_custom_target(TestBTN test-binarytreenode
                  DEPENDS test-binarytreenode)
add_custom_target(TestBT test-binarytree
                  DEPENDS test-binarytree)
add_custom_target(TestD test-dijkstra
                  DEPENDS test-dijkstra)
add_custom_target(TestMH test-minheap
                  DEPENDS test-minheap)
add_custom_target(TestPoly test-poly
                  DEPENDS test-poly)
add_custom_target(TestFS test-filesystem
                  DEPENDS test-filesystem)
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
add_custom_target(TestAS test-alphabetsoup
                  DEPENDS test-alphabetsoup)
add_custom_target(TestH test-hash
                  DEPENDS test-hash)
add_custom_target(TestBB test-balancebraces
                  DEPENDS test-balancebraces)
add_custom_target(TestQ test-queue
                  DEPENDS test-queue)
add_custom_target(TestHC test-hascycle
                  DEPENDS test-hascycle)
add_custom_target(TestF test-fibonacci
                  DEPENDS test-fibonacci)
add_custom_target(TestA test-atomics
                  DEPENDS test-atomics)
add_custom_target(TestKeyPad test-keypad
                  DEPENDS test-keypad)
add_custom_target(TestLL test-linkedlist
                  DEPENDS test-linkedlist)
                                    
add_custom_target(Test
                  DEPENDS TestNode TestStack TestFIFO TestSFIFO TestDLL TestBTN TestD TestMH TestPoly TestFS TestR TestGLW TestLC TestMS TestTC TestAS TestH TestBB TestQ TestHC TestF TestLL TestKeyPad)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unit-tests unit-tests/gtest-linkedlist.cpp unit-tests/gtest-main.cpp)
target_link_libraries(unit-tests GTest::GTest GTest::Main)

add_test(LinkedListTests unit-tests)

                  