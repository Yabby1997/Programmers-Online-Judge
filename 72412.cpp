#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> formatted;

void parseGivenInfo(string &info, int pointer, string parsed) {
    string current;
    
    if(info[pointer] >= 48 && info[pointer] <= 57) {
        formatted[parsed].push_back(stoi(info.substr(pointer)));
        return;
    }
        
    string check = info.substr(pointer, 2);
    if(check == "ja") current = "java";
    else if(check == "py") current = "python";
    else if(check == "cp") current = "cpp";
    else if(check == "ba") current = "backend";
    else if(check == "fr") current = "frontend";
    else if(check == "ju") current = "junior";
    else if(check == "se") current = "senior";
    else if(check == "ch") current = "chicken";
    else if(check == "pi") current = "pizza";
    
    parseGivenInfo(info, pointer + current.size() + 1, parsed + current[0]);
    parseGivenInfo(info, pointer + current.size() + 1, parsed + '-');
}

void processQuery(string &query, int pointer, string parsed, vector<int> &answer) {
    string current;
    
    if(query[pointer] >= 48 && query[pointer] <= 57) {
        int score = stoi(query.substr(pointer));
        vector<int> scores = formatted[parsed];

        int count = 0;
        for(auto each : scores) if(each >= score) count++;
        answer.push_back(count);
        return;
    }
    
    string check = query.substr(pointer, 2);
    if(check == "- ") current = "-";
    else if(check == "ja") current = "java";
    else if(check == "py") current = "python";
    else if(check == "cp") current = "cpp";
    else if(check == "ba") current = "backend";
    else if(check == "fr") current = "frontend";
    else if(check == "ju") current = "junior";
    else if(check == "se") current = "senior";
    else if(check == "ch") current = "chicken";
    else if(check == "pi") current = "pizza";
    
    if(query[pointer + current.size() + 1] == 'a') processQuery(query, pointer + current.size() + 5, parsed + current[0], answer);
    else processQuery(query, pointer + current.size() + 1, parsed + current[0], answer);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i = 0; i < info.size(); i++) parseGivenInfo(info[i], 0, "");
    for(auto each : query) processQuery(each, 0, "", answer);
    
    return answer;
}
