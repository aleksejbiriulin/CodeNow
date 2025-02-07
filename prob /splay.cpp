#include <cassert>
#include <iostream>
#include <random>

// I give from semenrist

std::mt19937 rd;

class TreapMap {
  struct Node {
    uint32_t prior;  // y
    int key;        // x
    int sum;

    Node* left;
    Node* right;

    Node(const int& key)
        : prior(rd()), key(key), sum(key), left(nullptr), right(nullptr) {}
  };

 public:
  // HW TODO=)
  // Contains
  // operator[]
  // Size()
  // Empty()
  // begin(), end()
  // ~TreapMap

  ~TreapMap() { Clear(root_); }

  void Insert(const int& key) {
    auto [t1, t2] = Split(root_, key);
    root_ = Merge(Merge(t1, new Node(key)), t2);
  }

  std::pair<Node*, Node*> At(const int& key) {
    return Find(nullptr, root_, key);
  }

  void Erase(const int& key) {
    auto [parent, to_erase] = Find(nullptr, root_, key);
    if (to_erase == nullptr) {
      return;
    }
    if (parent == nullptr) {
      root_ = Merge(to_erase->left, to_erase->right);
      delete to_erase;
      return;
    }
    if (parent->left == to_erase) {
      parent->left = Merge(to_erase->left, to_erase->right);
    } else {
      parent->right = Merge(to_erase->left, to_erase->right);
    }
    delete to_erase;
  }

 private:
  std::pair<Node*, Node*> Find(Node* parent, Node* node, const int& key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (node->key == key) {
      return {parent, node};
    }
    if (node->key < key) {
      return Find(node, node->right, key);
    }
    return Find(node, node->left, key);
  }

  std::pair<Node*, Node*> Split(Node* node, const int& key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (key < node->key) {
      auto [t1, t2] = Split(node->left, key);
      node->left = t2;
      return {t1, node};
    }
    auto [t1, t2] = Split(node->right, key);
    node->right = t1;
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
      Node* new_right = Merge(t1->right, t2);
      t1->right = new_right;
      return t1;
    }
    Node* new_left = Merge(t1, t2->left);
    t2->left = new_left;
    return t2;
  }

   Node* Next(Node* node, const int& key) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->key < key) {
      Node* node1 = Next(node->right, key);
      if (node1 == nullptr) {
        return node;
      }
      return node1;
    }
    return Next(node->left, key);
  }

  void Clear(Node* node) {
    if (node == nullptr) {
      return;
    }
    Clear(node->left);
    Clear(node->right);
    delete node;
  }

  Node* root_{nullptr};
};

int main() {
  const long long kModule = 1e9;
  TreapMap tree;
  char type;
  long long value;
  long long value_right;
  int number;
  long long last_next = 0;
  std::cin >> number;
  for (; number > 0; number--) {
    std::cin >> type >> value;
    if (type == '+') {
      tree.Insert((value + last_next) % kModule);
      last_next = 0;
    } else {
      std::cin >> value_right;
      last_next = tree.RangeSum(value, value_right);
      std::cout << last_next << std::endl;
    }
  }
}
