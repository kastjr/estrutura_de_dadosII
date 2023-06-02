#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 7);
    root = insertNode(root, 6);
    root = insertNode(root, 22);
    root = insertNode(root, 14);
    root = insertNode(root, 40);
    root = insertNode(root, 63);

    cout << "Árvore binária em ordem: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
