#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


class valid_sudoku {
    public:
    bool isValid(vector<vector<char>>& board) {
        int n = board.size();
        int rowcase[9][9] = {0};
        int colcase[9][9] = {0};
        int gridcase[9][9] = {0};

        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';

                    int k = i / 3 * 3 + j / 3;
                    if(rowcase[i][num-1]++ || colcase[j][num-1]++ || gridcase[k][num-1]++) { 
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    valid_sudoku v;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
        };
        cout << boolalpha << v.isValid(board) << endl;
        return 0;
        
}