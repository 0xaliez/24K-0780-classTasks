#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    

public:
    DynamicArray(int initialCapacity = 2) {
        size = 0;
        capacity = initialCapacity;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }
    
	void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void print() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray arr;
    for (int i = 1; i <= 10; ++i) {
        arr.push_back(i);
        cout << "Inserted: " << i
                  << ", Size: " << arr.getSize()
                  << ", Capacity: " << arr.getCapacity()
                  << endl;
    }
    arr.print();
    return 0;
}

