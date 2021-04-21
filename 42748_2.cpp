#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command : commands) {
        int from = command[0] - 1;
        int to = command[1];
        int index = command[2] - 1;
        
        vector<int> subVector = vector(array.begin() + from, array.begin() + to);
        sort(subVector.begin(), subVector.end());
        answer.push_back(subVector[index]);
    }
    
    return answer;
}
