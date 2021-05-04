#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    
    vector<string> numberAndOperators;
    unordered_set<char> uniqueOperators;
    
    int from = 0;
    int to = 1;
    
    while(to <= expression.size()) {
        if(expression[to] == '+' || expression[to] == '*' || expression[to] == '/' || expression[to] == '-') {
            numberAndOperators.push_back(string(expression.begin() + from, expression.begin() + to));
            numberAndOperators.push_back(string(expression.begin() + to, expression.begin() + to + 1));
            uniqueOperators.insert(expression[to]);
            from = to + 1;
            to = to + 2;
            continue;
        } else if(expression[to] == '\0') {
            numberAndOperators.push_back(string(expression.begin() + from, expression.begin() + to));
            break;
        }
        to++;
    }
    
    vector<char> uniqueOps(uniqueOperators.begin(), uniqueOperators.end());
    sort(uniqueOps.begin(), uniqueOps.end());
    long long best = 0;
    do {
        vector<string> temp1 = numberAndOperators;
        vector<string> temp2;
        for(int i = 0; i < uniqueOps.size(); i++) {
            char currentOperation = uniqueOps[i];
            
            for(int i = 0; i < temp1.size(); i++) {
                if(temp1[i][0] == currentOperation) {
                    if(currentOperation == '+') {
                        temp2[temp2.size() - 1] = to_string(stoll(temp2.back()) + stoll(temp1[i + 1]));
                    } else if(currentOperation == '*') {
                        temp2[temp2.size() - 1] = to_string(stoll(temp2.back()) * stoll(temp1[i + 1]));
                    } else if(currentOperation == '-') {
                        temp2[temp2.size() - 1] = to_string(stoll(temp2.back()) - stoll(temp1[i + 1]));
                    }
                    i += 1;
                    
                } else {
                    temp2.push_back(temp1[i]);
                }
            }
            temp1 = temp2;
            temp2.clear();
        }
        long long currentBest = abs(stoll(temp1[0]));
        if(best < currentBest) {
            best = currentBest;
        }
    } while(next_permutation(uniqueOps.begin(), uniqueOps.end()));
    
    return best;
}
