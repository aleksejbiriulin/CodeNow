#include <boost/dynamic_bitset.hpp>
#include <iostream>

int main() {
  size_t n = 15;
  boost::dynamic_bitset<> a(n);
  boost::dynamic_bitset<> b(n);
  boost::dynamic_bitset<> c(n);
  boost::dynamic_bitset<> zero(n);
  for (size_t i = 0; i < n; ++i) {
    a[i] = (56 >> i) & 1;
    b[i] = (5679 >> i) & 1;
    c[i] = ((5679 + 56) >> i) & 1;
  }
  while (b != zero) {
    boost::dynamic_bitset<> a1(10);
    a1 = a;
    a ^= b;
    b &= a1;
    b <<= 1;
  }

  std::cout << a << " " << 56 + 5679 << " " << c << std::endl;
  std::cout << sizeof(unsigned char);
  void* m = malloc(n);
  void* k = malloc(n);
  for (size_t iter = 0; iter < n; ++iter) {
    // Приведение указателей к типу char* для доступа по байтам
    ((unsigned char*)k)[iter] =
        ((unsigned char*)k)[iter] ^ ((unsigned char*)m)[iter];
  }

  delete[] m;
}