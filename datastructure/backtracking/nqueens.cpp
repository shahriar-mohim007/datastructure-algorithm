#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>board;
vector<vector<string>>solutions;
bool issafe(int row, int col, int n) {
   
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

   
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}


void solveNqueens(int row,int n)
{
    if (row == n) {
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string row_str;
            for (int j = 0; j < n; j++) {
                row_str += (board[i][j] == 1) ? "Q" : ".";
            }
            solution.push_back(row_str);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (issafe(row, col, n)) {
            board[row][col] = 1; 
            solveNqueens(row + 1, n);
            board[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    board.resize(n,vector<int>(n,0));
    solveNqueens(0,n);
    for (const vector<string>& solution : solutions) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
}