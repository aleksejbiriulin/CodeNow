#include <cstddef>
#include <vector>

class RingBuffer {
 public:
  explicit RingBuffer(size_t capacity): kCapacity_(capacity) {
    buffer_.resize(capacity);
  }

  size_t Size() const { return size_; }

  bool Empty() const { return size_ == 0; }

  bool TryPush(int element) {
    if (size_ < kCapacity_) {
      ++size_;
      buffer_[BackPointer_] = element;
      ++BackPointer_;
      BackPointer_ %= kCapacity_;
      return true;
    }
    return false;
  }

  bool TryPop(int* element) {
    if (size_ == 0) {
      *element = -1;
      return false;
    }
    *element = buffer_[FrontPointer_];
    ++FrontPointer_;
    FrontPointer_ %= kCapacity_;
    --size_;
    return true;
  }
private:
 std::vector<int> buffer_;
 size_t size_;
 const size_t kCapacity_;
 size_t FrontPointer_ = 0;
 size_t BackPointer_ = 0;
};
