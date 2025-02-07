#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Tree {
 private:
  struct Node {
    long long value;
    int height, size;
    Node* left;
    Node* right;

    Node(long long val)
        : value(val), height(1), size(1), left(nullptr), right(nullptr) {}
  };

  Node* root_;

  int height(Node* node) { return node == nullptr ? 0 : node->height; }

  int size(Node* node) { return node == nullptr ? 0 : node->size; }

  int balanceFactor(Node* node) {
    return height(node->left) - height(node->right);
  }

  void updateNode(Node* node) {
    node->height = max(height(node->left), height(node->right)) + 1;
    node->size = size(node->left) + size(node->right) + 1;
  }

  Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateNode(y);
    updateNode(x);
    return x;
  }

  Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateNode(x);
    updateNode(y);
    return y;
  }

  Node* balance(Node* node) {
    updateNode(node);
    if (balanceFactor(node) > 1) {
      if (balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
      }
      return rotateRight(node);
    }
    if (balanceFactor(node) < -1) {
      if (balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
      }
      return rotateLeft(node);
    }
    return node;
  }

 public:
  Tree() : root_(nullptr) {}

  void insert(long long value) { root_ = insert(root_, value); }

 private:
  Node* insert(Node* node, long long value) {
    if (node == nullptr) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = insert(node->left, value);
    } else if (value > node->value) {
      node->right = insert(node->right, value);
    } else {
      return node;
    }
    return balance(node);
  }

 public:
  void deleteValue(long long value) { root_ = deleteNode(root_, value); }

 private:
  Node* deleteNode(Node* node, long long value) {
    if (node == nullptr) {
      return nullptr;
    }
    if (value < node->value) {
      node->left = deleteNode(node->left, value);
    } else if (value > node->value) {
      node->right = deleteNode(node->right, value);
    } else {
      if (node->left == nullptr || node->right == nullptr) {
        Node* temp = node->left ? node->left : node->right;
        delete node;
        return temp;
      } else {
        Node* minNode = findMin(node->right);
        node->value = minNode->value;
        node->right = deleteNode(node->right, minNode->value);
      }
    }
    if (node != nullptr) {
      node = balance(node);
    }
    return node;
  }

  Node* findMin(Node* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

 public:
  bool exists(long long value) { return exists(root_, value); }

 private:
  bool exists(Node* node, long long value) {
    if (node == nullptr) {
      return false;
    }
    if (value == node->value) {
      return true;
    } else if (value < node->value) {
      return exists(node->left, value);
    } else {
      return exists(node->right, value);
    }
  }

 public:
  string next(long long value) {
    Node* node = root_;
    long long* result = nullptr;
    while (node != nullptr) {
      if (node->value > value) {
        result = &node->value;
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return result == nullptr ? "none" : to_string(*result);
  }

  string prev(long long value) {
    Node* node = root_;
    long long* result = nullptr;
    while (node != nullptr) {
      if (node->value < value) {
        result = &node->value;
        node = node->right;
      } else {
        node = node->left;
      }
    }
    return result == nullptr ? "none" : to_string(*result);
  }

  string kth(int k) { return kth(root_, k); }

 private:
  string kth(Node* node, int k) {
    if (node == nullptr) {
      return "none";
    }
    int leftSize = size(node->left);
    if (leftSize == k) {
      return to_string(node->value);
    } else if (leftSize > k) {
      return kth(node->left, k);
    } else {
      return kth(node->right, k - leftSize - 1);
    }
  }

 public:
  string toString() {
    Node* curr = root_;
    if (curr == nullptr) {
      return "";
    }
    string res;
    stack<Node*> st;
    while (curr != nullptr || !st.empty()) {
      while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      res += to_string(curr->value) + ' ';
      curr = curr->right;
    }
    return res;
  }
};

int main() {
  Tree tree;
  string filePath = "input.txt";
  ifstream infile(filePath);
  if (!infile) {
    cerr << "Unable to open file " << filePath << endl;
    return 1;
  }
  string str;
  while (getline(infile, str)) {
    istringstream ss(str);
    string command;
    ss >> command;
    if (command == "insert") {
      long long value;
      ss >> value;
      tree.insert(value);
    } else if (command == "delete") {
      long long value;
      ss >> value;
      tree.deleteValue(value);
    } else if (command == "exists") {
      long long value;
      ss >> value;
      cout << (tree.exists(value) ? "true" : "false") << endl;
    } else if (command == "next") {
      long long value;
      ss >> value;
      cout << tree.next(value) << endl;
    } else if (command == "prev") {
      long long value;
      ss >> value;
      cout << tree.prev(value) << endl;
    } else if (command == "kth") {
      int k;
      ss >> k;
      cout << tree.kth(k) << endl;
    }
  }
  infile.close();
  return 0;
}