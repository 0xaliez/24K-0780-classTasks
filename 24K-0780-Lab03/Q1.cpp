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

    void insertAtStart(string value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
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

    void insertAfter(string afterValue, string newValue) {
        Node* temp = head;
        while (temp != NULL && temp->data != afterValue) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Book " << afterValue << " not found.\n";
            return;
        }
        Node* n = new Node(newValue);
        n->next = temp->next;
        temp->next = n;
    }

    bool searchBook(string value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        cout << "Books in Library:\n";
        while (temp != NULL) {
            cout << "-> " << temp->data << "\n";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Singly books;

    books.insertAtTail("Data Structures");
    books.insertAtTail("Operating Systems");
    books.insertAtTail("Computer Networks");
    books.insertAtTail("Database Systems");

    books.insertAtStart("Artificial Intelligence");
    books.insertAtTail("Machine Learning");
    books.insertAfter("Operating Systems", "Cyber Security");

    string bookToSearch = "Database Systems";
    if (books.searchBook(bookToSearch))
        cout << "Book " << bookToSearch << " found in library.\n";
    else
        cout << "Book " << bookToSearch << " NOT found.\n";

    books.display();

    return 0;
}

