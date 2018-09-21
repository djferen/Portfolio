
#include "linkedlist.h"
#include "gtest/gtest.h"

namespace {

typedef linkedlist <int> int_ll_type;

TEST(LinkedListTests, Initialization) {

  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  int_ll_type a_int_ll(iarray, isize);

  EXPECT_EQ(a_int_ll.getLength(), 5);

  EXPECT_EQ(a_int_ll.getTailNode()->data, 5);
}

TEST(LinkedListTests, ReverseByPtr) {

  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  int_ll_type a_int_ll(iarray, isize);

  a_int_ll.reverseByPtr();

  EXPECT_EQ(a_int_ll.getTailNode()->data, 1);
}

TEST(LinkedListTests, ReverseByStack) {

  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  int_ll_type a_int_ll(iarray, isize);

  a_int_ll.reverseByStack();

  EXPECT_EQ(a_int_ll.getTailNode()->data, 1);
}

TEST(LinkedListTests, MoveConstructor){
  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  int_ll_type a_int_ll(iarray, isize);

  int_ll_type b_int_ll(a_int_ll);

  std::cout << "After copy, a_int_ll contains: " << a_int_ll << std::endl;

  std::cout << "After copy, b_int_ll contains: " << b_int_ll << std::endl;

  std::cout << "After copy, a_int_ll contains: " << a_int_ll << std::endl;
}

TEST(LinkedListTests, MoveMethod){
  size_t isize = 5;
  int iarray[isize] = {1, 2, 3, 4, 5};

  int_ll_type a_int_ll(iarray, isize);

  int_ll_type b_int_ll(std::move(a_int_ll));
}

TEST(LinkedListTests, EmptyLLCycle){
  int_ll_type empty_int_ll;

  EXPECT_EQ(empty_int_ll.containsCycle(), false);
}

TEST(LinkedListsTests, LLCycle){
  size_t dsize = 10;
  int darray[dsize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int_ll_type d_int_ll (darray, dsize);

  EXPECT_EQ(d_int_ll.containsCycle(), false);

  int_ll_type::linktype mid_link = d_int_ll.getLink(3);

  EXPECT_NE(mid_link, nullptr);

  int_ll_type::linktype tail_node = d_int_ll.getTailNode();

  if(tail_node != nullptr)
  {
	  tail_node->next = mid_link;
  }

  EXPECT_EQ(d_int_ll.containsCycle(), true);
}

}
