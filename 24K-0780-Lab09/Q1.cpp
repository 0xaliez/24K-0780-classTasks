#include <iostream>
using namespace std;

class Student{
    public:
        int rollNo;
        Student* left;
        Student* right;
        int height;
    
    Student(int val){
        rollNo = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

int height(Student* root) {
    if (root == NULL)
        return -1; 

    return 1 + max(height(root->left), height(root->right));
}

int getBalance(Student* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Student* rightRotate(Student* y) {
    Student* x = y->left;
    Student* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Student* leftRotate(Student* x) {
    Student* y = x->right;
    Student* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Student* insert(Student* node, int key){
    if(node == NULL){
        return new Student(key);
    }
    
    if(key < node->rollNo){
        node->left = insert(node->left, key);
    } else if(key > node->rollNo){
        node->right = insert(node->right, key);
    } else {
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if(balance > 1 && key < node->left->rollNo){
        return rightRotate(node);
    }
    if(balance < -1 && key > node->right->rollNo){
        return leftRotate(node);
    }
    if(balance > 1 && key > node->left->rollNo){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key < node->right->rollNo){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void inorder(Student* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->rollNo << " ";
    inorder(root->right);
}

int main(){
    Student* root = new Student(10);
    
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    
    cout << "AVL Tree inorder before insertion and rotation: " << endl;
    inorder(root);
    
    root = insert(root, 15);
    
    cout << "\nHeight of the AVL tree after inserting 15: " << height(root) << endl;
    cout << "AVL Tree inorder after insertion and rotation: " << endl;
    inorder(root);
    
    return 0;
}

