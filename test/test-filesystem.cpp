
#include "filesystem.h"
#include <iostream>

int main() {
  FileSystem fs;
  fs.listDirectory();
  fs.isDirectory("/");
  fs.changeDirectory("/temp");
  return 0;
}
