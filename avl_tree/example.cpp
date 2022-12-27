#include <iostream>
#include <algorithm>

struct Node {
  int val;
  int height;
  Node* left;
  Node* right;
};

int height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int getBalanceFactor(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
  node->height = std::max(height(node->left), height(node->right)) + 1;
}

Node* rotateRight(Node* node) {
  Node* newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;
  updateHeight(node);
  updateHeight(newRoot);
  return newRoot;
}

Node* rotateLeft(Node* node) {
  Node* newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
  updateHeight(node);
  updateHeight(newRoot);
  return newRoot;
}

Node* balance(Node* node) {
  updateHeight(node);
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor == 2) {
    if (getBalanceFactor(node->left) < 0) {
      node->left = rotateLeft(node->left);
    }
    return rotateRight(node);
  } else if (balanceFactor == -2) {
    if (getBalanceFactor(node->right) > 0) {
      node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
  }
  return node;
}

Node* insert(Node* node, int val) {
  if (node == nullptr) {
    return new Node{val, 1, nullptr, nullptr};
  }
  if (val < node->val) {
    node->left = insert(node->left, val);
  } else {
    node->right = insert(node->right, val);
  }
  return balance(node);
}

Node* remove(Node* node, int val) {
  if (node == nullptr) {
    return nullptr;
  }

  if (val < node->val) {
    node->left = remove(node->left, val);
  } 
  else if (val > node->val) {
    node->right = remove(node->right, val);
  } 
  
  else {
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      return nullptr;
    } else if (node->left == nullptr) {
      Node* temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
        Node* temp = node->left; 
        delete node;
        return temp;
    } else {
        Node* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->val = temp->val;
        node->right = remove(node->right, temp->val);
    }
    }
    return balance(node);
}

void print(Node* node){
    if (node == nullptr) {
        return;
    }
    print(node->left);
    std::cout << node->val << " ";
    print(node->right);
}

int main() {
  Node* root = nullptr;
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 8);
  print(root);
  std::cout << std::endl;
  root = remove(root, 7);
  print(root);
  std::cout << std::endl;
  return 0;
}
