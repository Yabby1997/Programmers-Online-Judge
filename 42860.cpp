#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> sequence;
int moveRight(int index);
int moveLeft(int index);

int solution(string name) {
    int answer = 0;
    
    for(int i = 0; i < name.size(); i++) {
        int requiredControls = name[i] - 65;
        requiredControls = requiredControls > 13 ? 26 - requiredControls : requiredControls;
        answer += requiredControls;
        sequence.push_back(requiredControls == 0);
    }
    
    int index = 0;
    int rightBest = 0;
    vector<bool> temp = sequence;
    temp[0] = true;
    while(true) {
        if(all_of(temp.begin(), temp.end(), [](bool a){ return a; })) {
            break;
        }
        index = moveRight(index);
        temp[index] = true;
        rightBest += 1;
    }
    
    int leftBest = 200000000;
    for(int rightEnd = 0; rightEnd < sequence.size() / 2; rightEnd++) {
        vector<bool> temp = sequence;
        replace(temp.begin(), temp.begin() + rightEnd + 1, false, true);
        int currentBest = 2 * rightEnd;
        int index = 0;
        while(true) {
            if(all_of(temp.begin(), temp.end(), [](bool a){ return a; })) {
                break;
            }
            index = moveLeft(index);
            temp[index] = true;
            currentBest += 1;
        }
        if(currentBest < leftBest) leftBest = currentBest;
    }
    
    answer += (rightBest < leftBest ? rightBest : leftBest);
    
    return answer;
}

int moveRight(int index) {
    return index + 1 < sequence.size() ? index + 1 : index;
}

int moveLeft(int index) {
    return index - 1 < 0 ? sequence.size() - 1 : index - 1;
}
