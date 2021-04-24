#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board){
    int answer = 0;
    int row = board.size();
    int col = board[0].size();
    int filterMaxSize = row > col ? col : row;
    
    for(auto row : board) {
        if(any_of(row.begin(), row.end(), [](int a) { return a == 1; })) {
            answer = 1;
            break;
        }
    }
    
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            if(board[i][j] >= 1 && board[i - 1][j - 1] >= 1 && board[i][j - 1] >= 1 && board[i - 1][j] >= 1) {
                int size = board[i - 1][j - 1];
                if(board[i][j - 1] < size) {
                    size = board[i][j - 1];
                }
                if(board[i - 1][j] < size) {
                    size = board[i - 1][j];
                }
                board[i][j] = size + 1;
                answer = answer > board[i][j] ? answer : board[i][j];
            }
        }
    }
    
    answer *= answer;
    
    return answer;
}
