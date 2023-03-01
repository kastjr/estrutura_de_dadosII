struct Node {
    int data;
    Node* left;
    Node* right;
};

/* se a raiz é nula, a árvore é vazia e não tem nós; senao conta a raiz e somamos com o número de nós na subárvore 
esquerda e na subárvore direita. */
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
