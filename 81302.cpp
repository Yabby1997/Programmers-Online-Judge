#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Position {
    int row;
    int col;
    int distance;
    int direction;
};

vector<int> rowDirections = {-1, 1, 0, 0};
vector<int> colDirections = {0, 0, -1, 1};

queue<Position> getIntervieweeQueue(vector<string> &room) {
    queue<Position> intervieweeQueue;
    for(int row = 0; row < room.size(); row++) {
        for(int col = 0; col < room[0].size(); col++) {
            if(room[row][col] == 'P') intervieweeQueue.push(Position{row, col, 0, -1});
        }
    }
    return intervieweeQueue;
}

bool examineRoom(vector<string> &room) {
    queue<Position> intervieweeQueue = getIntervieweeQueue(room);
    
    while(!intervieweeQueue.empty()) {
        Position currentPosition = intervieweeQueue.front();
        intervieweeQueue.pop();
        
        for(int direction = 0; direction < rowDirections.size(); direction++) {
            if(currentPosition.direction != -1 && (currentPosition.direction + direction == 1 || currentPosition.direction + direction == 5)) continue;
            int nextRow = currentPosition.row + rowDirections[direction];
            int nextCol = currentPosition.col + colDirections[direction];
            int nextDistance = currentPosition.distance + 1;
            
            if(nextDistance > 2 || nextRow < 0 || nextRow >= room.size() || nextCol < 0 || nextCol >= room[0].size() || room[nextRow][nextCol] == 'X') continue;
            if(room[nextRow][nextCol] == 'P') return false;
            intervieweeQueue.push(Position{nextRow, nextCol, nextDistance, direction});
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto eachRoom : places) {
        if(examineRoom(eachRoom)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}
