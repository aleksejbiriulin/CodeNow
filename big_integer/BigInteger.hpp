#include <string>
#include <vector>

class BigInteger {
 public:
  BigInteger();
  template<typename T>
  BigInteger(T);
  BigInteger(const std::string&);
  BigInteger(const BigInteger&);
  ~BigInteger();
  BigInteger& operator=(const BigInteger&);
  BigInteger& operator+=(const BigInteger&);
  BigInteger& operator-=(const BigInteger&);
  BigInteger& operator*=(const BigInteger&);
  BigInteger& operator/=(const BigInteger&);
  BigInteger& operator%=(const BigInteger&);
  BigInteger operator-() const;
  BigInteger& operator++();
  BigInteger operator++(int);
  BigInteger& operator--();
  BigInteger operator--(int);
  friend BigInteger operator+(BigInteger, const BigInteger&);
  friend BigInteger operator-(BigInteger, const BigInteger&);
  friend BigInteger operator*(BigInteger, const BigInteger&);
  friend BigInteger operator/(BigInteger, const BigInteger&);
  friend BigInteger operator%(BigInteger, const BigInteger&);
  friend bool operator==(const BigInteger&, const BigInteger&);
  friend bool operator!=(const BigInteger&, const BigInteger&);
  friend bool operator<=(const BigInteger&, const BigInteger&);
  friend bool operator>=(const BigInteger&, const BigInteger&);
  friend bool operator<(const BigInteger&, const BigInteger&);
  friend bool operator>(const BigInteger&, const BigInteger&);
  friend std::istream& operator>>(std::istream&, BigInteger&);
  friend std::ostream& operator<<(std::ostream&, const BigInteger&);
  explicit operator bool() const;

 private:
  // первый бит знак 0 положительно, 1 отрицательно.
  std::vector<bool> bits;
  std::string toString() const;
};

BigInteger operator"" _bi(const char* str, size_t) {
  return BigInteger(std::string(str));
}

template<typename T>
BigInteger::BigInteger(T num) {
  if (num == 0) {
    bits.resize(2, 0);
    return;
  }
  size_t size_ = 0;
  T num1 = num;
  if (num1 < 0) {
    num1 *= -1;
  }
  while (num1 > 0) {
    ++size_;
    num1 >>= 1;
  }
  bits.resize(size_ + 1);
  if (num < 0) {
    bits[0] = 1;
  }
  for (; size_ > 0; --size_) {
    bits[size_ + 1] = (num >> (size_ - 1)) & 1;
  }
}

BigInteger::BigInteger(const std::string& str) {
  if (str.size() == 0)
}
