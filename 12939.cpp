#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> numbers;
    
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, ' ')) numbers.push_back(stoi(temp));
    
    sort(numbers.begin(), numbers.end());
    
    answer += to_string(numbers.front());
    answer += " ";
    answer += to_string(numbers.back());
    
    return answer;
}
