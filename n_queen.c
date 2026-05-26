#include<stdio.h>
#include<stdbool.h>

#define N 6

int board[N][N];

bool isSafe(int row, int col){
    int i, j;

    for(i = 0;i < col;i++)
        if(board[row][i])
            return false;
    
    for(i = row, j = col; i >= 0 && j >= 0; i--,j--)
        if(board[i][j])
            return false;
    
    for(i = row, j = col; i < N && j >= 0; i++, j--)
        if(board[i][j])
            return false;
    
    return true;
}

bool solve(int col){
    if(col >= N)
        return true;

    for(int row = 0;row < N;row++){
        if(isSafe(row, col)){
            board[row][col] = 1;

            if(solve(col + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(){
    for(int i = 0;i < N;i++){
        for(int j = 0; j < N;j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    if(solve(0))
        printBoard();
    else
        printf("Solution does not exist\n");

    return 0;
}




















// Time Complexity: Exponential (approx): O(N!) in the worst-case
// Space Complexity: O(N^2) (board) + O(N) recursion stack
// Explanation: N-Queens uses backtracking exploring many permutations of placements;
// the search tree grows exponentially. The board stores N^2 and recursion depth is O(N).