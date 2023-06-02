#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    for (Node* child : root->children) {
        preOrderTraversal(child);
    }
}

int main() {
    // Criando a árvore alinhada
    Node* root = createNode(1);

    Node* child1 = createNode(2);
    Node* child2 = createNode(3);
    Node* child3 = createNode(4);

    Node* grandchild1 = createNode(5);
    Node* grandchild2 = createNode(6);

    addChild(root, child1);
    addChild(root, child2);
    addChild(root, child3);

    addChild(child2, grandchild1);
    addChild(child2, grandchild2);

    // Percurso pre-order
    cout << "Percurso pre-order: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}

resultado

    1
   /|\
  2 3 4
    / \
   5   6
