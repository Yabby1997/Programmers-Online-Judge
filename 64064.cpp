#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isCandidate(string potentialCandidate, string banned) {
    if(potentialCandidate.size() == banned.size()) {
        for(int i = 0; i < potentialCandidate.size(); i++) {
            if(potentialCandidate[i] != banned[i] && banned[i] != '*')
                return false;
        }
        return true;
    }
    return false;
}

void solveRecursively(int depth, vector<string>& banned, unordered_map<string, unordered_set<string>>& candidates, unordered_set<string> picked, unordered_set<string>& setOfPicked) {
    if(picked.size() == banned.size()) {
        vector<string> temp(picked.begin(), picked.end());
        sort(temp.begin(), temp.end());
        string tempString = "";
        for(auto each : temp) {
            tempString += each;
        }
        setOfPicked.insert(tempString);
        return;
    }
    
    string current = banned[depth];
    for(auto each : candidates[current]) {
        if(picked.find(each) == picked.end()) {
            unordered_set<string> newPicked = picked;
            newPicked.insert(each);
            solveRecursively(depth + 1, banned, candidates, newPicked, setOfPicked);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    unordered_map<string, unordered_set<string>> candidates;
    
    for(auto each : user_id) {
        for(auto banned : banned_id) {
            if(isCandidate(each, banned)) {
                candidates[banned].insert(each);
            }
        }
    }
    unordered_set<string> setOfPicked{};
    
    solveRecursively(0, banned_id, candidates, unordered_set<string>(), setOfPicked);
    answer = setOfPicked.size();
    
    return answer;
}
