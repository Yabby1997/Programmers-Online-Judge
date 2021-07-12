#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, pair<char, int>> keywordToNumberAndOffset = {
    {"ze", {'0', 4}},
    {"on", {'1', 3}},
    {"tw", {'2', 3}},
    {"th", {'3', 5}},
    {"fo", {'4', 4}},
    {"fi", {'5', 4}},
    {"si", {'6', 3}},
    {"se", {'7', 5}},
    {"ei", {'8', 5}},
    {"ni", {'9', 4}},
};

void convertStringRecursively(string &s, int index, string &answer) {
    if(index >= s.length()) return;
    
    if(s[index] <= 57 && s[index] >= 48) {
        answer += (s[index] + '\0');
        return convertStringRecursively(s, index + 1, answer);
    }
    
    auto numberAndOffset = keywordToNumberAndOffset[s.substr(index, 2)];
    answer += numberAndOffset.first;
    return convertStringRecursively(s, index + numberAndOffset.second, answer);
}

int solution(string s) {
    string answer = "";
    convertStringRecursively(s, 0, answer);    
    return stoi(answer);
}
