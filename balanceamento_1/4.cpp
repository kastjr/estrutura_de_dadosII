#include <iostream>
#include <vector>
#include <algorithm>

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

Node* constructBalancedTree(vector<int>& sortedValues, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = createNode(sortedValues[mid]);

    root->left = constructBalancedTree(sortedValues, start, mid - 1);
    root->right = constructBalancedTree(sortedValues, mid + 1, end);

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
    vector<int> values = {7, 6, 22, 14, 40, 63};

    sort(values.begin(), values.end());

    Node* root = constructBalancedTree(values, 0, values.size() - 1);

    cout << "Árvore binária em ordem: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
