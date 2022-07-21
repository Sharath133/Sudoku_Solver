bool UnassignedLocation(int board[N][N],int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (board[row][col] == UNASSIGNED)
                return true;
    return false;
}
}