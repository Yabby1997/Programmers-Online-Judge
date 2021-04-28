#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> xDirection = {-1, 1, 0, 0};
vector<int> yDirection = {0, 0, -1, 1};
vector<pair<int, int>> coordinates;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    vector<int> sizeOfArea = {0};
    
    int row = picture.size();
    int col = picture[0].size();
    
    vector<vector<int>> area(row, vector<int>(col, 0));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(picture[i][j] != 0)
                coordinates.push_back(make_pair(i, j));
        }
    }
    
    while(!coordinates.empty()) {
        auto current = coordinates.back();
        coordinates.pop_back();
        int currentX = current.first;
        int currentY = current.second;
        
        if(area[currentX][currentY] == 0) {
            area[currentX][currentY] = ++number_of_area;
            sizeOfArea.push_back(1);
        }
        
        for(int i = 0; i < xDirection.size(); i++) {
            int nextX = currentX + xDirection[i];
            int nextY = currentY + yDirection[i];
            
            if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || picture[nextX][nextY] != picture[currentX][currentY] || area[nextX][nextY] != 0)
                continue;
        
            area[nextX][nextY] = area[currentX][currentY];
            sizeOfArea[area[nextX][nextY]]++;
            coordinates.push_back(make_pair(nextX, nextY));
        }
    }
    
    sort(sizeOfArea.begin(), sizeOfArea.end(), [](int a, int b) { return a > b; });
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = sizeOfArea[0];
    return answer;
}
