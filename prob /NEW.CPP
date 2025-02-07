#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
 private:
  struct Node {
    int key;
    int prefer;
    Node* left;
    Node* right;
    int sum;
  };

  static void FixSum(Node* node) {
    node->sum = node->key;
    if (node->left != nullptr) {
      node->sum += node->left->sum;
    }
    if (node->right != nullptr) {
      node->sum += node->right->sum;
    }
  }
 public:
  Tree() {

  }
  
  void insert(int key) {

  }
};

int main() {
 
}