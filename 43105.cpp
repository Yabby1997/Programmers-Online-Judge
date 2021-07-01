#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<int> previous = triangle[0];
    
    for(int i = 1; i < triangle.size(); i++) {
        vector<int> current = triangle[i];
        vector<int> temp(current.size(), 0);
        
        for(int j = 0; j < previous.size(); j++) {
            temp[j] = max(current[j] + previous[j], temp[j]);
            temp[j + 1] = max(current[j + 1] + previous[j], temp[j + 1]);
        }
        previous = temp;
    }
    
    return *max_element(previous.begin(), previous.end());
}
