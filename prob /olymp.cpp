#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  unsigned long long n, b;
  std::cin >> n >> b;
  std::vector<unsigned long long> a(n);
  for (auto& iter : a) {
    std::cin >> iter;
  }
  unsigned long long answer = 0;
  unsigned long long pairs = 0;
  std::unordered_map<unsigned long long, unsigned long long> count;
  for (auto& iter : a) {
    if (iter == (1 << b) - 1) {
      answer += pairs;
    }
    pairs += count[(1 << b) - 1 - iter];
    count[iter] += 1;

  }
  std::cout << answer;
}