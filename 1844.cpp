#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> rowDirections = {-1, 1, 0, 0};
vector<int> colDirections = {0, 0, -1, 1};

struct Coordinate {
    int row;
    int col;
};

int solution(vector<vector<int>> maps) {
    queue<Coordinate> searchQueue;
    
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    
    searchQueue.push(Coordinate{0, 0});
    
    while(!searchQueue.empty()) {
        auto currentCoordinate = searchQueue.front();
        searchQueue.pop();
        int currentRow = currentCoordinate.row;
        int currentCol = currentCoordinate.col;
        int nextDistance = maps[currentRow][currentCol] + 1;
        
        for(int i = 0; i < rowDirections.size(); i++) {
            int nextRow = currentRow + rowDirections[i];
            int nextCol = currentCol + colDirections[i];
            
            if(nextRow < 0 || nextRow > n || nextCol < 0 || nextCol > m || maps[nextRow][nextCol] == 0) continue;
            
            if(maps[nextRow][nextCol] > nextDistance || maps[nextRow][nextCol] == 1) {
                maps[nextRow][nextCol] = nextDistance;
                searchQueue.push(Coordinate{nextRow, nextCol});
            }
        }
    }
    
    return maps[n][m] == 1 ? -1 : maps[n][m];
}
