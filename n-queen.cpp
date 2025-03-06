#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
 

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) { // If all queens are placed, print solution

   for(auto parent:board){
    for(auto child:parent){
        if(child)     cout<<"Q"<<" ";
        else cout<<"."<<" ";
    }
       cout<<endl;
   }
   cout<<endl;
        return true; // Continue finding other solutions
    }

    bool foundSolution = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place queen
            foundSolution = solveNQueens(board, row + 1, n) || foundSolution;
            board[row][col] = 0; // Backtrack
        }
    }

    return foundSolution;
}
// Wrapper function to solve N-Queens
void nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQueens(board, 0, n)) {
        cout << -1<< endl;
    }
}

// Driver code
int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    nQueens(n);
    return 0;
}
