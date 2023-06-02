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

void inOrderTraversal(Node* root, vector<int>& values) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, values);
    values.push_back(root->data);
    inOrderTraversal(root->right, values);
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

int main() {
    Node* root = createNode(7);
    root->left = createNode(6);
    root->right = createNode(22);
    root->right->left = createNode(14);
    root->right->right = createNode(40);
    root->right->right->right = createNode(63);

    vector<int> values;
    inOrderTraversal(root, values);

    sort(values.begin(), values.end());

    Node* newRoot = constructBalancedTree(values, 0, values.size() - 1);

    cout << "Árvore binária em ordem: ";
    inOrderTraversal(newRoot, values);
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
