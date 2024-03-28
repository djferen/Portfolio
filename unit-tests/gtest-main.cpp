
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main()\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
