#include <iostream>

using namespace std;

class Node{
public:
    int employeeID;
    Node *left;
    Node *right;

    Node(int employeeID) : employeeID(employeeID), left(NULL), right(NULL) {}
};

int countNodes(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}


int countLeafNodes(Node* node) {
    if (node == NULL)
            return 0;
    if (node->left == NULL && node->right == NULL)
            return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int findHeight(Node* node) {
    if (node == NULL)
            return 0;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
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
	

	cout<<"Nodes: "<< countNodes(n1) << endl;
	cout<<"Leaf Nodes: "<< countLeafNodes(n1) << endl;
	cout<<"Height: "<< findHeight(n1) << endl;
}
