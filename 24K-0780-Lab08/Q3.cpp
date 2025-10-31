#include <iostream>

using namespace std;

class Node{
public:
    int employeeID;
    Node *left;
    Node *right;

    Node(int employeeID) : employeeID(employeeID), left(NULL), right(NULL) {}
};

bool isFullBinary(Node *root){
    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->left != NULL && root->right != NULL)
    {
        return isFullBinary(root->left) && isFullBinary(root->right);
    }

    return false;
}

Node* createNode(int employeeID){
	return new Node(employeeID);
}

void display(Node *node, int level)
{
    if (node == NULL)
    {
        return;
    }
    display(node->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }

    cout << " " << node->employeeID << endl;

    display(node->left, level + 1);
}

int main(){
	
    Node* n1 = new Node(100);
	n1->right = createNode(101);
	n1->left = createNode(102);
	n1->right->right = createNode(102);
	n1->right->left = createNode(103);
	n1->left->right = createNode(104);
	n1->left->left = createNode(105);
	
	if(isFullBinary(n1)){
		cout << "This is a full binary tree";
	} else {
		cout << "This is not a full binary tree";
	}
}
