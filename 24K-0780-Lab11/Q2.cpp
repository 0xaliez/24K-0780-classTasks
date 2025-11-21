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
    Node* table[100];

    HashTable() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    int hashFunc(string key){
		int sum = 0;
		for(int i=0; i<key.length(); i++){
			sum += key[i];
		}
		return sum%100;
	}

    void add_record(string key) {
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

    void print_dictionary() {
        for (int i = 0; i < 100; i++) {
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
    HashTable dictionary;
    dictionary.add_record("luck");
    dictionary.add_record("code");
    dictionary.add_record("apple");
    dictionary.add_record("star");
    dictionary.add_record("death");
    dictionary.add_record("computer");
    dictionary.add_record("books");
    dictionary.print_dictionary();
}

