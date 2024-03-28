/*
 * atomics.cpp
 *
 *  Created on: May 19, 2017
 *      Author: daniel
 */

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

/*This ready flag indicates whether the threads should begin to run.*/
std::atomic<bool> ready(false);

/*This winner flag indicates if a thread was able to win the race condition*/
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int id) {
  // wait for the ready to run signal
  while (!ready) {
    std::this_thread::yield();
  }

  // Run for awhile and don't optimize the loop
  for (volatile int i = 0; i < 1000000; ++i) {
  }

  // safely declare the winning thread
  if (!winner.test_and_set()) {
    std::cout << "thread #" << id << " won!\n";
  }
};

int main() {
  std::vector<std::thread> threads;

  std::cout << "spawning 10 threads that count to 1 million...\n";
  for (int i = 1; i <= 10; ++i)
    threads.push_back(std::thread(count1m, i));

  // Go threads
  ready = true;

  // Exited thread bodies and merge back to "parent"
  for (auto &th : threads)
    th.join();

  return 0;
}
