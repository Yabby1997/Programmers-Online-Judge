#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<pair<int, int>>> coordinates(rows, vector<pair<int, int>>());
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            coordinates[i].push_back(make_pair(i, j));
        }
    }
    
    vector<vector<pair<int, int>>> coordinatesTemp = coordinates;
    
    for(auto query : queries) {
        vector<vector<pair<int, int>>> originalCoordinates = coordinates;
        int rowMin = query[0] - 1, colMin = query[1] - 1, rowMax = query[2] - 1, colMax = query[3] - 1;
        int currentMin = 1000000;
        
        for(int i = rowMin; i <= rowMax; i++) {
            if(i != rowMax) coordinates[i][colMin] = originalCoordinates[i + 1][colMin];
            if(i != rowMin) coordinates[i][colMax] = originalCoordinates[i - 1][colMax];
            
            int candidateA = coordinates[i][colMin].first * columns + coordinates[i][colMin].second + 1;
            int candidateB = coordinates[i][colMax].first * columns + coordinates[i][colMax].second + 1;
            
            if(candidateA < currentMin) currentMin = candidateA;
            if(candidateB < currentMin) currentMin = candidateB;
        }
        
        for(int j = colMin; j <= colMax; j++) {
            if(j != colMax) coordinates[rowMax][j] = originalCoordinates[rowMax][j + 1];
            if(j != colMin) coordinates[rowMin][j] = originalCoordinates[rowMin][j - 1];
            
            int candidateA = coordinates[rowMax][j].first * columns + coordinates[rowMax][j].second + 1;
            int candidateB = coordinates[rowMin][j].first * columns + coordinates[rowMin][j].second + 1;
            
            if(candidateA < currentMin) currentMin = candidateA;
            if(candidateB < currentMin) currentMin = candidateB;
        }
        
        answer.push_back(currentMin);
    }
    
    return answer;
}
