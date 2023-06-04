// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 public:
  BST() :rootNode(nullptr) {}
  void AddValue(const T& value) {
    rootNode = addNode(rootNode, value);
  }
  int search(const T& value) {
    return searchNode(rootNode, value);
  }
  int depth() {
    return getDepth(rootNode) - 1;
  }

 private:
  struct Node {
    Node() :count(0), leftNode(nullptr), rightNode(nullptr) {}
    T value;
    int count;
    Node* leftNode;
    Node* rightNode;
  };
  Node* rootNode;

  Node* addNode(Node* rootNode, const T& value) {
    if (rootNode == nullptr) {
      rootNode = new Node;
      rootNode->value = value;
      rootNode->leftNode = nullptr;
      rootNode->rightNode = nullptr;
      rootNode->count = 1;
    } else if (rootNode->value > value) {
      rootNode->rightNode = addNode(rootNode->rightNode, value);
    } else if (rootNode->value < value) {
      rootNode->leftNode = addNode(rootNode->leftNode, value);
    } else {
      rootNode->count++;
    }
    return rootNode;
  }

  int searchNode(Node* root, const T& value) {
    if (root == nullptr) {
      return 0;
    } else if (root->value < value) {
      return searchNode(root->leftNode, value);
    } else if (root->value > value) {
      return searchNode(root->rightNode, value);
    } else if (root->value == value) {
      return root->count;
    }
    return 0;
  }

  int getDepth(Node* rootNode) {
    if (!rootNode) {
      return 0;
    }
    int rightTree = getDepth(rootNode->rightNode);
    int leftTree = getDepth(rootNode->leftNode);
    if (rightTree > leftTree) {
      return rightTree + 1;
    } else {
      return leftTree + 1;
    }
  }
};
#endif  // INCLUDE_BST_H_
