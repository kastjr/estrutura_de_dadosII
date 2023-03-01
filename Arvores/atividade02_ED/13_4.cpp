struct Node {
    int data;
    Node* left;
    Node* right;
};

int getHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}
