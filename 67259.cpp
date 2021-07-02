#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 1000000

using namespace std;

struct road {
    int direction;
    int row;
    int col;
};

vector<int> rowDirection = {-1, 1, 0, 0};
vector<int> colDirection = {0, 0, -1, 1};

int solution(vector<vector<int>> board) {
    int answer = INF;
    vector<vector<vector<int>>> costBoard(board.size(), vector<vector<int>>(board[0].size(), vector<int>(4, INF)));
    queue<road> roadQueue;
    roadQueue.push(road{-1, 0, 0});
    costBoard[0][0] = {0, 0, 0, 0};
    
    while(!roadQueue.empty()) {
        auto current = roadQueue.front();
        roadQueue.pop();
        
        for(int nextDirection = 0; nextDirection < rowDirection.size(); nextDirection++) {
            int nextRow = current.row + rowDirection[nextDirection];
            int nextCol = current.col + colDirection[nextDirection];
            
            if(nextRow < 0 || nextRow >= board.size() || nextCol < 0 || nextCol >= board[0].size() || board[nextRow][nextCol] == 1) continue;
            
            int estimatedCost = costBoard[current.row][current.col][current.direction] + (((nextDirection == current.direction) || (current.direction == -1)) ? 100 : 600);
            if(board[nextRow][nextCol] == 0 && costBoard[nextRow][nextCol][nextDirection] > estimatedCost) {
                costBoard[nextRow][nextCol][nextDirection] = estimatedCost;
                roadQueue.push(road{nextDirection, nextRow, nextCol});
            }
        }
    }
    
    for(auto each : costBoard[board.size() - 1][board[0].size() - 1]) answer = min(answer, each);
    
    return answer;
}
