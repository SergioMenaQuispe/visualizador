#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  vector<Node*> children;
};

Node* createNode(int key) {
  Node* newNode = new Node;
  newNode->key = key;
  return newNode;
}

void insertNode(Node* root, int key) {
  // Creamos un nuevo nodo con la clave dada
  Node* newNode = createNode(key);

  // Si el montículo está vacío, este es el nodo raíz
  if (!root) {
    root = newNode;
    cout<<root->key;
    return;
  }

  // Si no, buscamos el último nodo en el montículo y lo agregamos como hijo
  Node* current = root;
  while (!current->children.empty()) {
    current = current->children.back();
  }
  current->children.push_back(newNode);
}

void printGraph(Node* root) {
  if (root == nullptr) {
    cout<<"Hola";
    return;
  }
  cout << root->key << ": ";
  for (Node* child : root->children) {
    cout << child->key << " ";
  }
  cout << endl;
  for (Node* child : root->children) {
    printGraph(child);
  }
}


int main() {
  // Creamos un puntero nulo para nuestro montículo binomial
  Node* root = nullptr;

  // Insertamos algunos nodos en el montículo
  insertNode(root, 1);
  insertNode(root, 2);
  insertNode(root, 3);
  insertNode(root, 4);
  insertNode(root, 5);
  insertNode(root, 6);
  insertNode(root, 7);
  insertNode(root, 8);

  // Imprimimos el grafo del montículo binomial
  printGraph(root);
  return 0;
}
