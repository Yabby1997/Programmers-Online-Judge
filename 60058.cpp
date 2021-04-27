#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solveRecursively(string p) {
    string u = "";
    string v = "";
    
    int open = -1;
    int close = -1;
    
    if(p == "") {
        return p;
    }
    
    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '(') {
            open++;
        } else if(p[i] == ')') {
            close++;
        }
        
        if(open == close && open != -1) {
            u = string(p.begin(), p.begin() + i + 1);
            v = string(p.begin() + i + 1, p.end());
            break;
        }
    }
    
    // u가 올바른경우 v에 대해 재귀
    vector<char> temp;
    bool isCorrect = false;
    for(auto each : u) {
        if(each == '(') {
            temp.push_back(each);
        } else if(each == ')') {
            if(temp.empty()) {
                isCorrect = false;
                break;
            } else {
                temp.pop_back();
                isCorrect = true;
            }
        }
    }
    if(isCorrect) {
        return u + solveRecursively(v);
    }
    
    string trimmedU = string(u.begin() + 1, u.end() - 1);
    string reversedU = "";
    
    for(auto each : trimmedU) {
        if(each == '(') {
            reversedU.push_back(')');
        } else if(each == ')') {
            reversedU.push_back('(');
        }
    }
    
    return "(" + solveRecursively(v) + ")" + reversedU;
}

string solution(string p) {
    string answer = "";

    answer = solveRecursively(p);
    
    return answer;
}


