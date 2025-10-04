#include <iostream>

using namespace std;

int sols = 0;
char chess[20][20];

bool isSafe(int n, int r, int c) {
    for(int i = 0; i < r; i++){
        if(chess[i][c] == 'Q') return false;
	}
	
    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
        if(chess[i][j] == 'Q') return false;
	}
	
    for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++){
        if(chess[i][j] == 'Q') return false;
	}
	
    return true;
}

void nQ(int n, int row, bool &shown) {
    if(row == n) {
    	
        sols++;
        
        if(!shown) {
        	
            cout << "\nSafe placement (one board):\n";
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cout << chess[i][j] << " ";
                }
                cout << endl;
            }
            shown = true;
        }
        return;
    }

    for(int col=0; col<n; col++) {
    	
        if(isSafe(n,row,col)) {
            chess[row][col] = 'Q';
            nQ(n, row+1, shown);
            chess[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Chessboard size N: ";
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            chess[i][j] = '.';

    bool printed = false;
    nQ(n, 0, printed);

    cout << "Number of distinct safe board for N=" << n << " is " << sols << endl;
    return 0;
}
