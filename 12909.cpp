#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    vector<char> stack;
    
    for(char each : s) {
        if(stack.empty()) stack.push_back(each);
        else {
            if(stack.back() == '(' && each == ')') stack.pop_back();
            else stack.push_back(each);
        }
    }
    
    return stack.empty();
}
