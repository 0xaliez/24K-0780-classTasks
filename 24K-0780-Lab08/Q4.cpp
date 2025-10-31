#include <iostream>

using namespace std;

class Node{
public:
    int items;
    Node *left;
    Node *right;

    Node(int items) : items(items), left(NULL), right(NULL) {}
};

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

    cout << " " << node->items << endl;

    display(node->left, level + 1);
}

int subtreeSum(Node* node) {
    if (node == NULL){
		return 0;
	}
    
	return node->items + subtreeSum(node->left) + subtreeSum(node->right);
}

bool findSubtree(Node* node, int target) {
    if (node == NULL) return false;
    int sum = subtreeSum(node);
    if (sum == target) {
        display(node, 0);
        return true;
    }
    return findSubtree(node->left, target) || findSubtree(node->right, target);
}


Node* createNode(int items){
	return new Node(items);
}



int main(){
	
    Node* n1 = new Node(100);
	n1->right = createNode(101);
	n1->left = createNode(102);
	n1->right->right = createNode(102);
	n1->right->left = createNode(103);
	n1->left->right = createNode(104);
	n1->left->left = createNode(105);
	
	int n;
	cout << "Enter target sum for subtree: ";
	cin >> n;
	if(findSubtree(n1, n)){
		cout << "Subtree with sum " << n << " exists";
	} else {
		cout << "Subtree with sum " << n << " doesnt exist";
	}
	
}
