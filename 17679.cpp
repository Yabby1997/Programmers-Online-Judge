#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

void gravitateBoard(vector<vector<char>> &board) {
    vector<vector<char>> before = board;
    
    while(true) {
        for(int i = 1; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = ' ';
                }
            }
        }
        
        if(before == board) break;
        else before = board;
    }
}

bool check4Blocks(vector<vector<char>> &board, int &answer) {
    set<pair<int, int>> crushed;
    for(int i = 0; i < board.size() - 1; i++) {
        for(int j = 0; j < board[0].size() - 1; j++) {
            if(board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                crushed.insert(make_pair(i, j));
                crushed.insert(make_pair(i + 1, j));
                crushed.insert(make_pair(i, j + 1));
                crushed.insert(make_pair(i + 1, j + 1));
            }
        }
    }
    
    for(auto each : crushed) {
        board[each.first][each.second] = ' ';
        answer++;
    }
    
    return !crushed.empty();
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> charBoard;
    
    for(auto row : board) charBoard.push_back(vector<char>(row.begin(), row.end()));
    while(check4Blocks(charBoard, answer)) gravitateBoard(charBoard);
    
    return answer;
}
