#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void printBalance(Node* node) {
        if (node == NULL)
            return;
        printBalance(node->left);
        cout << "Node " << node->key << " | Height: " << node->height
             << " | Balance Factor: " << getBalance(node) << endl;
        printBalance(node->right);
    }
};

int main() {
    AVLTree tree;
    int elements[] = {10, 5, 15, 3, 7};
    for (int i = 0; i < 5; i++)
        tree.root = tree.insert(tree.root, elements[i]);

    tree.root = tree.insert(tree.root, 12);

    cout << "Inorder traversal of AVL tree:\n";
    tree.inorder(tree.root);
    cout << "\n\nNode details (height and balance factor):\n";
    tree.printBalance(tree.root);

    cout << "\nHeight of the AVL tree: " << tree.height(tree.root) << endl;

    return 0;
}

