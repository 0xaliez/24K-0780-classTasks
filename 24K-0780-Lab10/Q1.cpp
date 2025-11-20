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

        int parent(int i){
			return (i - 1) / 2;
		}
        int leftChild(int i){
			return (2 * i) + 1;
		}
        int rightChild(int i){
			return (2 * i) + 2;
		}


        void insertKey(int key){
        	
            if(size == capacity){
                cout <<"Heap overflow!"<<endl ;
                return;
            }
            
            size++;
            int i = size-1;
            arr[i] = key;
            
            while(i!=0 && arr[parent(i)] > arr[i]){
                swap(arr[i],arr[parent(i)]);
                i = parent(i);
            }
            
        }
        void display(){
            for(int i=0;i<size;i++){
                cout << arr[i] << " ";
            }
        }

};


int main(){
    Heap courier(5);
    courier.insertKey(1);
    courier.insertKey(3);
    courier.insertKey(4);
    courier.insertKey(5);

	cout << "Heap before inserting 2:" << endl;
    courier.display();
    cout <<endl;

    courier.insertKey(2);
	
	cout << "Heap after inserting 2:" << endl;
    courier.display();
}
