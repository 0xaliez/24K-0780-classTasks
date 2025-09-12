#include <iostream>

using namespace std;

class Dynamic2DMatrix {
private:
    int** data;
    int r;
    int c;

public:
    Dynamic2DMatrix(int rows, int columns) {
        r = rows;
        c = columns;

        data = new int*[r];
        for (int i = 0; i < r; i++) {
            data[i] = new int[c];
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                data[i][j] = i + j;
            }
        }
    }

    ~Dynamic2DMatrix() {
        for (int i = 0; i < r; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void resize(int newRows, int newColumns) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newData[i] = new int[newColumns];
        }

        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newColumns; j++) {
                newData[i][j] = 1;
            }
        }

        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newColumns; j++) {
                if (i < r && j < c) {
                    newData[i][j] = data[i][j];
                }
            }
        }

        for (int i = 0; i < r; i++) {
            delete[] data[i];
        }
        delete[] data;

        r = newRows;
        c = newColumns;
        data = newData;
    }

	void transpose(){
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				data[i][j] = data[j][i];
			}
		}
	}

    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << " " << data[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    Dynamic2DMatrix mat(3, 3);
    cout << "Initial matrix (3x3):" << endl;
    mat.display();

	cout << "\nTransposed matrix (3x3):" << endl;
    mat.transpose();
    mat.display();
	
	
    cout << "\nTruncated matrix (2x2):" << endl;
    mat.resize(2, 2);
    mat.display();

    cout << "\nEnglarged matrix (5x5):" << endl;
    mat.resize(5, 5);
    mat.display();


    return 0;
}

