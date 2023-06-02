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

void printTree(Node* root, int depth = 0) {
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << root->data << endl;

    for (Node* child : root->children) {
        printTree(child, depth + 1);
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

    // Imprimindo a árvore
    printTree(root);

    return 0;
}
