#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

bool correctParanthesisChecker(string &input) {
    vector<char> stack;
    
    stack.push_back(input[0]);
    for(int i = 1; i < input.size(); i++) {
        int difference = input[i] - stack.back();
        if(difference == 2 || difference == 1) stack.pop_back();
        else stack.push_back(input[i]);
    }
    
    return stack.empty();
}

int solution(string s) {
    int answer = 0;
    list<char> sList(s.begin(), s.end());
    
    for(int i = 0; i < s.size(); i++) {
        string current = string(sList.begin(), sList.end());
        if(correctParanthesisChecker(current)) answer++;
        char temp = sList.front();
        sList.pop_front();
        sList.push_back(temp);
    }

    return answer;
}
