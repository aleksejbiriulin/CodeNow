#include <algorithm>

#include "tree.h"

std::pair<int, int> Balance(TreeNode* node) {
  if (node == nullptr) return std::make_pair(0, 0);
  if (node->left == nullptr && node->right == nullptr) {
    node->balance = 0;
    return std::make_pair(1, 1);
  }
  auto [left_nodes, left_leafs] = Balance(node->left);
  auto [right_nodes, right_leafs] = Balance(node->right);
  node->balance = (left_nodes + right_nodes + 1) - (left_leafs + right_leafs);
  return std::make_pair(left_nodes + right_nodes + 1, left_leafs + right_leafs);
}

void Balance(Tree& tree) { Balance(tree.root); }

TreeNode* removeNodesWithBalance(TreeNode* node, int X) {
  if (node == nullptr) return nullptr;

  // Рекурсивно обрабатываем левое и правое поддеревья
  node->left = removeNodesWithBalance(node->left, X);
  node->right = removeNodesWithBalance(node->right, X);

  // Если текущая вершина имеет баланс X, удаляем её
  if (node->balance == X) {
    // Если у вершины нет потомков, просто удаляем её
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      return nullptr;
    }
    // Если есть только один потомок, заменяем вершину на него
    else if (node->left == nullptr) {
      TreeNode* temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      TreeNode* temp = node->left;
      delete node;
      return temp;
    }
    // Если есть два потомка, заменяем на поддерево с меньшим балансом
    else {
      if (node->left->balance <= node->right->balance) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      } else {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      }
    }
  }

  // Если баланс не равен X, оставляем вершину без изменений
  return node;
}
