#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Doubly {
private:
    Node* head;
    Node* tail;

public:
    Doubly() {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void deleteAtFront() {
        if (head == NULL) {
            cout << "No compartments to remove.\n";
            return;
        }
        cout << "Removed compartment: " << head->data << endl;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete temp;
    }

    void searchCompartment(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Compartment " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Compartment " << value << " not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "No compartments in the train.\n";
            return;
        }
        cout << "Train compartments (front to end): ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse() {
        if (tail == NULL) {
            cout << "No compartments in the train.\n";
            return;
        }
        cout << "Train compartments (end to front): ";
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    Doubly train;

    train.insertAtTail(101);
    train.insertAtTail(102);
    train.insertAtTail(103);
    train.insertAtTail(104);

    train.display();
    train.displayReverse();

    train.deleteAtFront();

    train.searchCompartment(103);
    train.searchCompartment(110);

    train.display();
    train.displayReverse();

    return 0;
}

