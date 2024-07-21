#include<iostream>
#include<math.h>
using namespace std;

bool boardValidity(int board[][9], int a, int b, int i ,int n){
    for(int j = 0; j<n; j++){
        if(board[a][j] == i){
            return false;
        } 
        else if(board[j][b] == i){
            return false;
        }   
    }
    int s_n = sqrt(n);
    int starting_index_a = a - a % s_n;
    int starting_index_b = b - b % s_n;

    for(int k = starting_index_a; k < starting_index_a+s_n; k++){
        for(int l = starting_index_b; l < starting_index_b+s_n; l++){
            if(board[a][b] == i){
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[][9], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool solveSudoku(int board[][9], int a, int b, int n){
    if(a==n){
        printBoard(board, n);
        return true;
    }
    if(b == n){
        return solveSudoku(board, a+1, 0, n);
    }
    if(board[a][b] != 0){
        return solveSudoku(board, a, b+1, n);
    }

    for(int i = 1; i<=n; i++){
        if(boardValidity(board, a, b, i, n)){
            board[a][b] = i;
            if(solveSudoku(board, a, b+1, n)){
                return true;
            }
            board[a][b] = 0;
        }
    }
    return false;

}

int main(){
    int n = 9;
    int board[9][9]{
        {0, 0, 7, 1, 0, 0, 0, 6, 0},
        {1, 0 ,5, 2, 0, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 7, 1, 2, 0},
        {3, 1, 2, 4, 0, 5, 0, 0, 8},
        {0, 0, 6, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {0, 0, 1, 0, 0, 4, 9, 8, 6},
        {8, 0, 3, 9, 0, 6, 0, 0, 0},
        {0, 6, 0, 0, 8, 2, 7, 0, 3}
    };
    solveSudoku(board, 0, 0, n);
    return 0;
}