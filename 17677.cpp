#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

bool makeItem(vector<char> &item, int index, string str) {
    if(index >= str.size()) return false;
    
    char target = str[index];
    if(target >= 97 && target <= 122) {
        item.push_back(target - 32);
        if(item.size() == 2) return true;
        else return makeItem(item, index + 1, str);
    } else if(target >= 65 && target <= 90) {
        item.push_back(target);
        if(item.size() == 2) return true;
        else return makeItem(item, index + 1, str);
    } else return false;
}

unordered_map<string, int> formatString(string str) {
    unordered_map<string, int> formatted;
    
    for(int i = 0; i < str.size() - 1; i++) {
        vector<char> item;
        if(makeItem(item, i, str)) formatted[string(item.begin(), item.end())] += 1;
    }
    return formatted;
}

int solution(string str1, string str2) {
    int numberOfIntersections = 0;
    int numberOfUnions = 0;
    set<string> alreadyCheckedItem;
    
    auto formattedMap1 = formatString(str1);
    auto formattedMap2 = formatString(str2);
    
    if(formattedMap1.empty() && formattedMap2.empty()) return 65536;
    
    for(auto each : formattedMap1) {
        if(formattedMap2.find(each.first) != formattedMap2.end()) {
            numberOfIntersections += min(each.second, formattedMap2[each.first]);
            numberOfUnions += max(each.second, formattedMap2[each.first]);
        } else {
            numberOfUnions += each.second;
        }
        alreadyCheckedItem.insert(each.first);
    }
    
    for(auto each : formattedMap2) {
        if(alreadyCheckedItem.find(each.first) == alreadyCheckedItem.end()) {
            numberOfUnions += each.second;
        }
    }
    
    return (int)((65536 * numberOfIntersections) / numberOfUnions);
}
