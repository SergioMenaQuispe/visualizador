#include <iostream>
#include <vector>
#include 

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

void createGraph(Node* root, string outputFile) {
  // Inicializa el contexto de Graphviz
  GVC_t* gvc = gvContext();

  // Crea un nuevo grafo
  Agraph_t* graph = agopen("graph", Agdirected, 0);

  // Crea una función recursiva para recorrer el árbol y crear los nodos y enlaces
  function<void(Node*, Agnode_t*)> traverse;
  traverse = [&](Node* node, Agnode_t* parent) {
    // Crea un nuevo nodo en el grafo con la clave del nodo actual
    char label[32];
    sprintf(label, "%d", node->key);
    Agnode_t* current = agnode(graph, label, 1);

    // Si hay un nodo padre, crea un enlace entre ellos
    if (parent != nullptr) {
      agedge(graph, parent, current, 0, 1);
    }

    // Llama a la función recursivamente para cada hijo del nodo actual
    for (Node* child : node->children) {
      traverse(child, current);
    }
  };

  // Inicia la recursión desde el nodo raíz
  traverse(root, nullptr);

  // Genera el gráfico y lo escribe a un archivo
  gvLayout(gvc, graph, "dot");
  gvRenderFilename(gvc, graph, "png", outputFile.c_str());

  // Limpia los recursos de Graphviz
  gvFreeLayout(gvc, graph);
  agclose(graph);
  gvFreeContext(gvc);
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
