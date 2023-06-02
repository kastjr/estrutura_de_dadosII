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

void morrisInOrderTraversal(Node* root) {
    Node* current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    cout << "Árvore binária em ordem (Morris Traversal): ";
    morrisInOrderTraversal(root);
    cout << endl;

    return 0;
}




1 - Espaço O(1): Uma das principais características do algoritmo de Morris é que ele realiza o percurso in-order da árvore sem usar espaço adicional, ou seja, seu espaço de memória é constante O(1). Isso significa que não há necessidade de uma pilha ou de armazenar ponteiros extras para realizar o percurso.

2 - Modificação dos ponteiros: O algoritmo de Morris realiza uma modificação temporária nos ponteiros da árvore para construir uma "thread" entre os nós durante o percurso. Essas threads permitem que o algoritmo avance pela árvore sem usar espaço adicional.

3- Travessia eficiente em ordem: O algoritmo de Morris realiza a travessia em ordem da árvore de forma eficiente, visitando os nós em sequência crescente de valores. Ele realiza uma visita in-order sem usar pilha ou recursão adicional.

4- Restauração dos ponteiros: Após a visita de um nó, os ponteiros temporariamente modificados pelo algoritmo de Morris são restaurados ao estado original, garantindo que a estrutura da árvore não seja alterada permanentemente.