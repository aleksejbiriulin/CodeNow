#include <iostream>
#include <vector>

using namespace std;
struct Node {
  char data;
  bool wordEnd = false;
  vector<Node*> to;

  Node(char data, bool wordEnd) : data(data), wordEnd(wordEnd) {}

  ~Node () {
    for (auto x : to) {
      delete(x);
    }
  }
};

typedef Node* PNode;

PNode root;

void addNode(PNode node1, PNode node2) {
  node1->to.push_back(node2);
}

void addWord(string word, size_t index, PNode node) {
  char s = word[index];
  bool flag = false;
  for (auto x : node->to) {
    if (x->data == s && index < word.length() - 1) {
      addWord(word, index + 1, x);
      flag = true;
      break;
    }
    else if (x->data == s && index == word.length() - 1) {
      x->wordEnd = true;
      flag = true;
      break;
    }
  }
  
  if (!flag) {
    PNode n = new Node(s, false);

    if (index == word.length() - 1)
      n->wordEnd = true;

    addNode(node, n);

    if (index != word.length() - 1)
    addWord(word, index + 1, n);
  }
}

void findWord(string word, size_t index, PNode node) {
  char s = word[index];
  bool flag = 0;
  for (auto x : node->to) {
    if (x->data == s && index < word.length() - 1) {
      flag = 1;
      findWord(word, index + 1, x);
    }
    else if (x->data == s && index == word.length() - 1 && x->wordEnd == true) {
      flag = 1;
      cout << "Yep";
    }
  }
  if (!flag)
    cout << "Nope";
}

int main() {
  root = new Node(' ', false);
  addWord("Eat", 0, root);
  findWord("Eat", 0, root);
}
