struct Node {
    int data;
    Node* left;
    Node* right;
};

bool hasElement(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == x) {
        return true;
    }
    return hasElement(root->left, x) || hasElement(root->right, x);
}
