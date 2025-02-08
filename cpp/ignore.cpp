#include <vector>

class Ignore {
 public:
  template <typename T>
  Ignore& operator=(const T&) {
    return *this;
  }
};

Ignore ignore = Ignore();
int main() {
  std::vector<int> a = {1, 2, 3};
  ignore = a;
  ignore = 1;
  ignore = 1.5;
}