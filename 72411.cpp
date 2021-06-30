#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> rankOfCourses;
unordered_map<int, int> highestRank;

void pickMenus(string order, int numberOfPicks, vector<string> &answer) {
    
    if(numberOfPicks > order.size()) return;
    
    vector<bool> mask(order.size() - numberOfPicks, false);
    mask.insert(mask.end(), numberOfPicks, true);
    
    do {
        string candidate;
        for(int pick = 0; pick < order.size(); pick++) if(mask[pick]) candidate += order[pick];
        rankOfCourses[candidate] += 1;
        if(highestRank[numberOfPicks] < rankOfCourses[candidate]) highestRank[numberOfPicks] = rankOfCourses[candidate];
    } while(next_permutation(mask.begin(), mask.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string order : orders) {
        sort(order.begin(), order.end());
        for(auto numberOfPicks : course) {
            pickMenus(order, numberOfPicks, answer);
        }
    }
    
    for(auto each : rankOfCourses) {
        string course = each.first;
        int numberOfPicks = course.size();
        int orderCount = each.second;
        
        if(orderCount < 2) continue;
        if(orderCount == highestRank[numberOfPicks]) answer.push_back(course);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
