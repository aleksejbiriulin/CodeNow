#include <cassert>
#include <iostream>
#include <random>

// I give from semenrist

std::mt19937 rd;

template <class KeyT, class ValueT>
class TreapMap {
  struct Node {
    uint32_t prior;  // y
    KeyT key;        // x

    ValueT value;

    Node* string1;
    Node* string2;

    Node(const KeyT& key, const ValueT& value)
        : prior(rd()), key(key), value(value), string1(nullptr), string2(nullptr) {}
  };

 public:
  ~TreapMap() { Clean(root_); }

  void Insert(const KeyT& key, const ValueT& value) {
    auto [t1, t2] = Split(root_, key);
    root_ = Merge(Merge(t1, new Node(key, value)), t2);
  }

  Node* At(const KeyT& key) {
    auto nodes = Find(nullptr, root_, key);
    if (nodes.socond == nullptr) {
      return nullptr;
    } else {
      return nodes.second;
    }
  }

  void Erase(const KeyT& key) {
    auto [parent, to_erase] = Find(nullptr, root_, key);
    if (to_erase == nullptr) {
      return;
    }
    if (parent == nullptr) {
      root_ = Merge(to_erase->string1, to_erase->string2);
      delete to_erase;
      return;
    }
    if (parent->string1 == to_erase) {
      parent->string1 = Merge(to_erase->string1, to_erase->string2);
    } else {
      parent->string2 = Merge(to_erase->string1, to_erase->string2);
    }
    delete to_erase;
  }

 private:
  void Clean(Node* node) {
    if (node == nullptr) {
      return;
    }
    Clean(node->string1);
    Clean(node->string2);
    delete node;
  }
  
  std::pair<Node*, Node*> Find(Node* parent, Node* node, const KeyT& key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (node->key == key) {
      return {parent, node};
    }
    if (node->key < key) {
      return Find(node, node->string2, key);
    }
    return Find(node, node->string1, key);
  }

  std::pair<Node*, Node*> Split(Node* node, const KeyT& key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (key < node->key) {
      auto [t1, t2] = Split(node->string1, key);
      node->string1 = t2;
      return {t1, node};
    }
    auto [t1, t2] = Split(node->string2, key);
    node->string2 = t1;
    return {node, t2};
  }

  Node* Merge(Node* t1, Node* t2) {
    if (t1 == nullptr) {
      return t2;
    }
    if (t2 == nullptr) {
      return t1;
    }
    if (t1->prior > t2->prior) {
      Node* new_string2 = Merge(t1->string2, t2);
      t1->string2 = new_string2;
      return t1;
    }
    Node* new_string1 = Merge(t1, t2->string1);
    t2->string1 = new_string1;
    return t2;
  }

  Node* root_{nullptr};
};

int main() {
  TreapMap<std::string, std::string> next;
  TreapMap<std::string, std::string> prev;
  std::string string1;
  std::string string2;
  int number;
  std::cin >> number;
  for (; number > 0; number--) {
    std::cin >> string1 >> string2;
    next.Insert(string1, string2);
    prev.Insert(string2, string1);
  }
  int qnumber;
  std::cin >> qnumber;
  for (; qnumber > 0; qnumber--) {
    std::cin >> string1;
    auto* node  = next.At(string1);
    if (node == nullptr) {
      std::cout << prev.At(string1)->value;
    } else {
      std::cout << node ->value;
    }
    std::cout << "\n";
  }
}
