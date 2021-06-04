#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> arr) {
    unordered_map<int, int> count;
    vector<int> answer = {};
    
    for(int each : arr) {
        count[each]++;
    }
    
    for(int each : arr) {
        if(count.find(each) == count.end() || count[each] == 1) {
            continue;
        } else {
            answer.push_back(count[each]);
            count.erase(each);
        }
    }
    
    if(answer.empty()) {
        answer.push_back(-1);
    }
    
    return answer;
}

int main() {
    vector<vector<int>> arr;
    
    arr.push_back(vector<int>{1, 2, 3, 3, 3, 3, 4, 4});
    arr.push_back(vector<int>{3, 2, 4, 4, 2, 5, 2, 5, 5});
    arr.push_back(vector<int>{3, 5, 7, 9, 1});
    
    for(int i = 0; i < arr.size(); i++) {
        auto answer = solution(arr[i]);
        
        cout<<"input "<<i<<endl;
        for(int each : answer) {
            cout<<each<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
