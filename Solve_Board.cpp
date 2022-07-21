bool Solveboard(int board[N][N])
{
    int row, col;
    if (!UnassignedLocation(board, row, col)) //If their is no unassigned location we return true
        return true;

    for (int x = 1; x <= 9; x++) 
    {
        if (valid(board, row, col, x)) // Checks for particular x it is valid or not to assign 
        {
            board[row][col] = x;  
            if (Solveboard(board)) // Return, if success -Recursively checks for other locations in board
                return true;
 
            // If above if statment fails we can't assign that x ,so try again for next x
            board[row][col] = UNASSIGNED;
        }
    }
    return false;
}