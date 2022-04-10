#include "Driver.h"
#include <time.h>

Driver::Driver(std::string filename) {
  file.open(filename);
  srand (time(NULL));
}

void Driver::test(int elements, int repeats) {
  auto sum = 0;
  file << "Test-int | elements: " << elements << " | repeats: " << repeats << " | Time: nanoseconds\n";
  for (int k = 0; k < repeats; ++k) {
    auto start = std::chrono::steady_clock::now(); //! start
    int data = randint(0, 2 * elements);
    int priority = randint(-1 * elements, 2 * elements);
    LinkedList<int> list(data, priority);
    for (int i = 0; i < elements - 1; ++i){
      data = randint(0, 2 * elements);
      priority = randint(-1 * elements, 2 * elements);
      list.add(data, priority);
    }
    auto end = std::chrono::steady_clock::now(); //! stop
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    file << time << " ns" << std::endl;
    sum += time;
  }
  file << "Average: " << sum / repeats << " ns";
}

int Driver::randint(int range_start, int range_end) {

  return (rand() % (range_end - range_start)) + range_start;
}

Driver::~Driver() {
  file.close();
}
