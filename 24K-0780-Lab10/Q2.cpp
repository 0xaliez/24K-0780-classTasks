#include <iostream>

using namespace std;

class Heap{
    int capacity;
    int size;
    int* arr;
    
public:
    Heap(int capacity): capacity(capacity),size(0){
        arr = new int[capacity];
    }

    int parent(int i){ return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void maxHeapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    int removeMax() {
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

        maxHeapify(0);

        return root;
    }



    void insertKey(int key){
        if(size == capacity){
            cout <<"Heap overflow!"<<endl ;
            return;
        }
            
        size++;
        int i = size-1;
        arr[i] = key;
            
        while(i!=0 && arr[parent(i)] < arr[i]){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
    void display(){
        for(int i =0;i<size;i++){
            cout << arr[i] << " ";
        }
    }

};


int main(){
    Heap hospital(10);
    
    hospital.insertKey(1);
    hospital.insertKey(2);
    hospital.insertKey(3);
    hospital.insertKey(5);
    hospital.insertKey(4);
    hospital.insertKey(6);
    hospital.insertKey(7);
    hospital.insertKey(8);
    hospital.insertKey(9);
    hospital.insertKey(10);
    
    cout << "Heap before removing max:" << endl;
    hospital.display();
    cout <<endl;
    
	cout << "Heap after removing max:" << endl;
    hospital.removeMax();
    hospital.display();
}
