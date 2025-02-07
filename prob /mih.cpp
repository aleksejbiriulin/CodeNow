#include <iostream>
#include <cstdlib> 

int main(int argc, char* argv[] ) {
  int* array_n = new int[argc];
  for (size_t iter = 0; iter < argc; iter++) {
    array_n[iter] = std::atoi(argv[iter]);
  }
  long long ans = 1;
  for (int iter = 0; iter < argc; iter++) {
    long long xter;
    long long sum_iter = 0;
    for (int jter = 0; jter < array_n[iter]; jter++) {
      std::cin >> xter;
      sum_iter += xter;
    }
    ans *= sum_iter;
  }
  delete[] array_n;
  std::cout << ans;
  return 0;
}
