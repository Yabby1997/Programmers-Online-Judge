#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> temp;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    cout<<commands.size()<<endl;
    for(int i = 0; i < commands.size(); i++){
        vector<int> command = commands[i];
        int from = command[0] - 1;
        int to = command[1] - 1;
        int ith = command[2] - 1;
        for(auto j = array.begin() + from; j <= array.begin() + to; j++){
            temp.push_back(*j);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[ith]);
        temp.clear();
    }
    return answer;
}
