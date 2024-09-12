#include <iostream>
using namespace std;

// Estrutura do nó da árvore AVL
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Função para criar um novo nó
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Novo nó é inicialmente adicionado na folha
    return node;
}

// Função para obter a altura de um nó
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Função para calcular o fator de balanceamento de um nó
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Função para atualizar a altura de um nó
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Rotação simples à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    updateHeight(y);
    updateHeight(x);

    // Retorna a nova raiz
    return x;
}

// Rotação simples à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    updateHeight(x);
    updateHeight(y);

    // Retorna a nova raiz
    return y;
}

// Inserção de um nó na árvore AVL
Node* insert(Node* node, int key) {
    // Inserção normal em uma árvore binária de busca
    if (!node)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Chaves iguais não são permitidas na árvore AVL
        return node;

    // Atualiza a altura do nó atual
    updateHeight(node);

    // Obtém o fator de balanceamento deste nó para verificar se ficou desbalanceado
    int balance = getBalance(node);

    // Caso 1: Rotação à direita (LL)
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Caso 2: Rotação à esquerda (RR)
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Caso 3: Rotação dupla à esquerda-direita (LR)
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso 4: Rotação dupla à direita-esquerda (RL)
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Retorna o nó (sem mudanças)
    return node;
}

// Função para imprimir a árvore (em ordem)
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Função principal
int main() {
    Node* root = nullptr;

    // Inserções na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Impressão da árvore AVL
    cout << "Árvore AVL em ordem: ";
    inOrder(root);

    return 0;
}