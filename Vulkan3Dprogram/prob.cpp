#include <iostream>
#include <type_traits>
#include <vector>
template <typename T>
struct S {
  T x;
  S(T x) : x(x) {}
  template <typename U>
  S(U s) : x(s.x) {}
};
template <int T>
int f() {
  T = 0;
}
int main() {
  S<int> s1(5);
  S<double> s2 = s1;
  std::cout << s1.x << s2.x;

  std::vector<int>::iterator i;
  constexpr bool is_const_vector = true;
  using value_type = std::conditional_t<is_const_vector, int, const int>;
}