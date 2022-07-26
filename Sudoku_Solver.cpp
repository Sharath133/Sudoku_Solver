//  To solve Sudoku problem using Backtracking algorithm in c++
#include<bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
const int N=9;

//This function checks whether the locations are unassigned or not
bool UnassignedLocation(int board[N][N],int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (board[row][col] == UNASSIGNED)
                return true;
    return false;
}


 
//checks whether assigned entry matches with any number in specified row
bool isPresentInRow(int board[N][N], int row, int x)
{
    for (int col = 0; col < N; col++)
        if (board[row][col] == x)
            return true;
    return false;
}
 
//checks whether assigned entry matches with any number in specified column
bool isPresentInCol(int board[N][N], int col, int x)
{
    for (int row = 0; row < N; row++)
        if (board[row][col] == x)
            return true;
    return false;
}
 
/* checks whether an assigned entry matches within the specified 3x3 box 
matches the given number.*/
bool isPresentInBox(int board[N][N], int StartRow,int StartCol, int x)
{
    for (int row = StartRow; row < StartRow+3; row++){
        for (int col = StartCol; col <StartCol+3; col++){
            if (board[row][col] == x)
                return true;}}
    return false;
}
 
// checks whether it will be valid  to assign x to the given row, col location. //
bool valid(int board[N][N], int row,int col, int x)
{
    
    /* Check if x is not already placed in current row, current column and current 3x3 box */
    return !isPresentInRow(board, row, x) && !isPresentInCol(board, col, x) && 
    !isPresentInBox(board, row - row % 3,col - col % 3, x) && board[row][col] == UNASSIGNED;
}

/* This function attempts to assign values to all unassigned locations in 
such a way to meet the requirements for Sudoku solution  */
bool Solveboard(int board[N][N])
{
    int row=0, col=0;
    if (!UnassignedLocation(board, row, col)) //If their is no unassigned location we return true
        return true;

    for (int x = 1; x <= 9; x++) 
    {
        if (valid(board, row, col, x)) // Checks for particular x it is valid or not to assign 
        {
            board[row][col] = x;  
            if (Solveboard(board)) 
                return true;
 
            // If above if statment fails we can't assign that x ,so try again for next x
            board[row][col] = UNASSIGNED;
        }
    }
    return false;
}
 
void printboard(int board[N][N]) //To print Grid
{
    for (int row = 0; row < N; row++) 
    {
        for (int col = 0; col < N; col++)
            cout << board[row][col] << " ";
        cout << endl;
    }
}
 

int main()
{
    // 0 means unassigned cells
    int board[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                       { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                       { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                       { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                       { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                       { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                       { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                       { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                       { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };
                       
    /*for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        cin>>board[i][j];
        }
    } */
    if (Solveboard(board) == true)
        printboard(board);
    else
        cout << "No solution exists";
 
    return 0;
    
}
