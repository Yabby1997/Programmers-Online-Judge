#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, bool> numberMap;

bool solution(vector<string> phone_book) {
    for(auto number : phone_book) {
        numberMap.insert(make_pair(number, false));
    }
    
    for(auto each : numberMap) {
        string number = each.first;
        for(int i = 0; i < number.size(); i++) {
            string subNumber = number.substr(0, i);
            if(numberMap.find(subNumber) != numberMap.end()) return false;
        }
    }
    
    return true;
}
