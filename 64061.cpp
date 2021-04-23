#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<queue<int>> boardByCol(board[0].size() + 1, queue<int>());
    deque<int> dolls;
    
    for(auto eachRow : board) {
        for(int i = 0; i < eachRow.size(); i++) {
            if(eachRow[i] != 0) {
                boardByCol[i + 1].push(eachRow[i]);
            }
        }
    }
    
    for(auto col : moves) {
        if(!boardByCol[col].empty()) {
            int newDoll = boardByCol[col].front();
            if(!dolls.empty() && dolls.back() == newDoll) {
                dolls.pop_back();
                answer += 2;
            } else {
                dolls.push_back(newDoll);
            }
            boardByCol[col].pop();
        }
    }
    
    return answer;
}
