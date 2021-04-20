#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> completionMap;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < completion.size(); i++) {
        auto iterator = completionMap.find(completion[i]);
        if(iterator != completionMap.end()) {
            iterator->second = iterator->second + 1;
        } else {
            completionMap.insert(make_pair(completion[i], 1));
        }
    }
    
    for(auto each : participant) {
        if(completionMap.find(each) == completionMap.end()) {
            answer = each;
            break;
        } else {
            auto iterator = completionMap.find(each);
            if(iterator->second <= 0) {
                answer = each;
                break;
            }
            iterator->second = iterator->second - 1;
        }
    }
    
    return answer;
}
