#include <iostream>

using namespace std;

class Node {
public:
    string key;
    Node* next;

    Node(string key) : key(key), next(NULL) {}
};

class HashTable {
public:
    Node* table[10];

    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    int hashFunc(string key){
		int sum = 0;
		for(int i=0; i<key.length(); i++){
			sum += key[i];
		}
		return sum%10;
	}

    void insert(string key) {
        int index = hashFunc(key);
        Node* newNode = new Node(key);

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable table;
    table.insert("apple");
    table.insert("banana");
    table.insert("mango");
    table.insert("grapes");
    table.insert("apple");
    table.insert("peach");
    table.display();
}

