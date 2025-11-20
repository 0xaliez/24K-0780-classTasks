#include <iostream>

using namespace std;

class Heap {
    int capacity;
    int size;
    int* arr;

public:
    Heap(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void minHeapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int smallest = i;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int removeMin() {
        if (size <= 0) {
            cout << "Heap empty" << endl;
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        minHeapify(0);

        return root;
    }

    void insertKey(int key) {
        if (size == capacity) {
            cout << "Heap overflow!" << endl;
            return;
        }

        size++;
        int i = size - 1;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap orders(10);

    orders.insertKey(100);
    orders.insertKey(50);
    orders.insertKey(75);
    orders.insertKey(60);

    cout << "Heap after inserting orders [100, 50, 75, 60]:" << endl;
    orders.display();

    cout << "Heap after inserting new order 55:" << endl;
    orders.insertKey(55);
    orders.display();

    cout << "Heap after removing lowest price order:" << endl;
    orders.removeMin();
    orders.display();
}

