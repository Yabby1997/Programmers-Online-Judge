#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<char> stack;
    
    for(auto each : s) {
        if(!stack.empty() && stack.back() == each) stack.pop_back();
        else stack.push_back(each);
    }

    return stack.empty() ? 1 : 0;
}
