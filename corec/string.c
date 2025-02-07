#include "string.h"

String::String(size_t size, char character) : size_(size), capacity_(size + 1) {
  delete[] data_;
  data_ = new char[capacity_];
  std::memset(data_, character, size);
  data_[size_] = '\0';
}

String::String(const char* str) : size_(strlen(str)), capacity_(size_) {
  delete[] data_;
  data_ = new char[capacity_ + 1];
  std::strcpy(data_, str);
}

String::String(const String& other)
    : size_(other.size_), capacity_(other.capacity_) {
  delete[] data_;
  data_ = new char[capacity_ + 1];
  if (size_ != 0) {
    std::strcpy(data_, other.data_);
  }
  data_[size_] = '\0';
}

String& String::operator=(const String& other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new char[capacity_ + 1];

    if (other.data_ != nullptr) {
      std::strcpy(data_, other.data_);
    } else {
      data_[0] = '\0';
    }
  }
  return *this;
}

String::~String() { delete[] data_; }

void String::Clear() { size_ = 0; }

void String::PushBack(char character) {
  if (size_ + 1 > capacity_) {
    Reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  data_[size_++] = character;
  data_[size_] = '\0';
}

void String::PopBack() {
  if (size_ > 0) {
    --size_;
    data_[size_] = '\0';
  }
}

void String::Resize(size_t new_size) {
  if (new_size > capacity_) {
    Reserve(new_size);
  }
  size_ = new_size;
  data_[size_] = '\0';
}

void String::Resize(size_t new_size, char character) {
  if (new_size > capacity_) {
    Reserve(new_size);
    for (size_t i = size_; i < new_size; ++i) {
      data_[i] = character;
    }
  }
  size_ = new_size;
  data_[size_] = '\0';
}

void String::Reserve(size_t new_cap) {
  if (new_cap > capacity_) {
    Allocate(new_cap);
    capacity_ = new_cap;
  }
}

void String::ShrinkToFit() {
  if (capacity_ > size_) {
    Allocate(size_);
    capacity_ = size_;
  }
}

void String::Swap(String& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

char& String::operator[](size_t index) { return data_[index]; }

const char& String::operator[](size_t index) const { return data_[index]; }

char& String::Front() { return data_[0]; }

const char& String::Front() const { return data_[0]; }

char& String::Back() { return data_[size_ - 1]; }

const char& String::Back() const { return data_[size_ - 1]; }

bool String::Empty() const { return size_ == 0; }

size_t String::Size() const { return size_; }

size_t String::Capacity() const { return capacity_; }

char* String::Data() { return data_; }
const char* String::Data() const { return data_; }

bool String::operator<(const String& other) const {
  return std::strcmp(data_, other.data_) < 0;
}

bool String::operator>(const String& other) const {
  return std::strcmp(data_, other.data_) > 0;
}

bool String::operator<=(const String& other) const {
  return std::strcmp(data_, other.data_) <= 0;
}

bool String::operator>=(const String& other) const {
  return std::strcmp(data_, other.data_) >= 0;
}

bool String::operator==(const String& other) const {
  if (Size() != other.Size()) {
    return false;
  }
  for (size_t letter = 0; letter < Size(); ++letter) {
    if (data_[letter] != other[letter]) {
      return false;
    }
  }
  return true;
}

bool String::operator!=(const String& other) const { return !(*this == other); }

String operator+(const String& self, const String& other) {
  // size_t size_ = self.Size();
  // String result(size_ + other.Size(), '\0');
  // for (size_t iter = 0; iter < size_; iter++) {
  //   result[iter] = self[iter];
  // }
  // for (size_t iter = size_; iter < size_ + other.Size(); iter++) {
  //   result[iter] = other[iter - size_];
  // }
  // // std::strcpy(result.data_, data_);`
  // // std::strcat(result.data_, other.data_);
  String result(self);
  result += other;
  return result;
}

String& String::operator+=(const String& other) {
  capacity_ = size_ + other.size_ + 1;
  Allocate(capacity_);
  for (size_t iter = size_; iter < size_ + other.Size(); iter++) {
    data_[iter] = other[iter - size_];
  }
  size_ += other.Size();
  data_[size_] = '\0';
  return *this;
}

String operator*(const String& str, size_t number) {
  String result = str;
  result *= number;
  return result;
}

String& String::operator*=(unsigned long long number) {
  if (number == 0) {
    *this = String();
    return *this;
  }

  String original = *this;
  String result;

  while (number > 0) {
    if (number % 2 == 1) {
      result += original;
    }
    original += original;
    number /= 2;
  }

  *this = result;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  if (!str.Empty()) {
    os << str.Data();
  }
  return os;
}

std::istream& operator>>(std::istream& is, String& str) {
  const size_t kBuffferSize = 1 << 10;
  char buffer[kBuffferSize];
  is >> buffer;
  str = String(buffer);
  return is;
}

std::vector<String> String::Split(const String& delim) const {
  std::vector<String> result(1);
  for (size_t iter = 0; iter < size_; ++iter) {
    bool flag = false;
    if (delim[0] == this->operator[](iter)) {
      flag = true;
      for (size_t delim_iter = 0; delim_iter < delim.size_; ++delim_iter) {
        if (iter + delim_iter < size_) {
          if (delim[delim_iter] != this->operator[](iter + delim_iter)) {
            flag = false;
            break;
          }
        } else {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      iter += delim.size_ - 1;
      result.push_back("");
      continue;
    }
    result.back() += String(1, this->operator[](iter));
  }
  return result;
}

String String::Join(const std::vector<String>& strings) {
  String result = String();
  for (size_t iter = 0; iter < strings.size(); iter++) {
    result += strings[iter];
    if (iter + 1 < strings.size()) {
      result += *this;
    }
  }
  *this = result;
  return *this;
}

void String::Allocate(size_t new_capacity) {
  char* new_data = new char[new_capacity + 1];
  if (data_ != nullptr) {
    std::strcpy(new_data, data_);
    delete[] data_;
  }
  data_ = new_data;
}
