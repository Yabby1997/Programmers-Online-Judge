#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

auto compare = [](const string& a, const string& b) {
    return stoll(a + b) < stoll(b + a);
};

priority_queue<string, vector<string>, decltype(compare)> numberQueue(compare);

string solution(vector<int> numbers) {
    string answer = "";

    for(auto number : numbers) {
        numberQueue.push(to_string(number));
    }
    
    while(!numberQueue.empty()) {
        if(answer != "0") answer += numberQueue.top();
        numberQueue.pop();
    }
    
    return answer;
}
