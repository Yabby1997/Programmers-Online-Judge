#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> clothesMap;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(auto each : clothes) {
        string category = each[1];
        if(clothesMap.find(category) == clothesMap.end()) {
            clothesMap[category] = 1;
        } else {
            clothesMap[category] += 1;
        }
    }
    
    for(auto each : clothesMap) {
        answer *= (each.second + 1);
    }
    answer -= 1;
    
    
    return answer;
}
