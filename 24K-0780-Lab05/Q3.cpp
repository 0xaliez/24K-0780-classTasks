#include <iostream>

using namespace std;

bool isSafe(int **maze, int r, int c, int n){
    if(r >= 0 && c >= 0 && r < n && c < n && maze[r][c] == 1){
        return true;
    }
    return false;
}

bool findPath(int **maze, int r, int c, int n, int **result){
	
    if(!isSafe(maze, r, c, n)) return false;
    if(result[r][c] == 1) return false;

    result[r][c] = 1;

    if(r == n-1 && c == n-1) return true;

    if(findPath(maze, r+1, c, n, result)) return true;
    if(findPath(maze, r, c+1, n, result)) return true;
    if(findPath(maze, r-1, c, n, result)) return true;
    if(findPath(maze, r, c-1, n, result)) return true;

    result[r][c] = 0;
    return false;
}

int main(){
    int n = 7;

    int grid[7][7] = {
        {1,0,1,1,1,0,1},
        {1,1,1,0,1,1,1},
        {0,1,0,1,0,1,0},
        {1,1,1,1,1,0,1},
        {0,0,0,0,1,1,1},
        {1,1,1,0,1,0,1},
        {0,0,1,1,1,1,1}
    };

    int **maze = new int*[n];
    int **result = new int*[n];

    for(int r=0; r<n; r++){
        maze[r] = new int[n];
        result[r] = new int[n];
        for(int c=0; c<n; c++){
            maze[r][c] = grid[r][c];
            result[r][c] = 0;
        }
    }

    if(findPath(maze, 0, 0, n, result)){
        cout << "Child reached the Ice Cream Shop!"<<endl;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                cout << result[r][c] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No path found"<<endl;
    }
}

