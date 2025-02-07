#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <vector>

class String {
 public:
  String() = default;
  String(size_t size, char character);
  String(const char* str);

  String(const String& other);
  String& operator=(const String& other);
  ~String();

  void Clear();
  void PushBack(char character);
  void PopBack();
  void Resize(size_t new_size);
  void Resize(size_t new_size, char character);
  void Reserve(size_t new_cap);
  void ShrinkToFit();
  void Swap(String& other);

  char& operator[](size_t index);
  const char& operator[](size_t index) const;

  char& Front();
  const char& Front() const;

  char& Back();
  const char& Back() const;

  bool Empty() const;
  size_t Size() const;
  size_t Capacity() const;
  char* Data();
  const char* Data() const;
  bool operator<(const String& other) const;
  bool operator>(const String& other) const;
  bool operator<=(const String& other) const;
  bool operator>=(const String& other) const;
  bool operator==(const String& other) const;
  bool operator!=(const String& other) const;

  String& operator+=(const String& other);
  String& operator*=(unsigned long long number);

  friend String operator*(const String& str, size_t number);

  friend std::ostream& operator<<(std::ostream& os, const String& str);
  friend std::istream& operator>>(std::istream& is, String& str);

  std::vector<String> Split(const String& delim = " ") const;
  String Join(const std::vector<String>& strings);

 private:
  char* data_{nullptr};
  size_t size_{0};
  size_t capacity_{0};

  void Allocate(size_t new_capacity);
};

String operator+(const String& self, const String& other);
#endif
