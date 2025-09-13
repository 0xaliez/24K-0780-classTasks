#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = NULL;
    }
};

class Singly {
private:
    Node* head;

public:
    Singly() {
        head = NULL;
    }

    void insertAtTail(string value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    void deleteAtFront() {
        if (head == NULL) {
            cout << "Catalog is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Deleted book: " << head->data << endl;
        head = head->next;
        delete temp;
    }

    void searchBook(string value) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Book \"" << value << "\" found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book \"" << value << "\" not found.\n";
    }

    void searchByPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (pos == position) {
                cout << "Book at position " << position << ": " << temp->data << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "No book at position " << position << ".\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Catalog is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Books in Catalog:\n";
        while (temp != NULL) {
            cout << "-> " << temp->data << "\n";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Singly catalog;

    catalog.insertAtTail("Data Structures");
    catalog.insertAtTail("Operating Systems");
    catalog.insertAtTail("Computer Networks");
    catalog.insertAtTail("Database Systems");

    catalog.display();

    catalog.deleteAtFront();

    catalog.searchBook("Database Systems");
    catalog.searchByPosition(2);

    catalog.display();

    return 0;
}

