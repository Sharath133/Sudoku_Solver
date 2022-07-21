bool valid(int board[N][N], int row,int col, int x)
{
    
    /* Check if x is not already placed in current row, current column and current 3x3 box */
    return !isPresentInRow(board, row, x) && !isPresentInCol(board, col, x) && 
    !isPresentInBox(board, row - row % 3,col - col % 3, x) && board[row][col] == UNASSIGNED;
}