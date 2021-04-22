#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    auto firstIter = first.begin();
    auto secondIter = second.begin();
    auto thirdIter = third.begin();
    vector<int> scores(4, 0);
    
    for(int eachAnswer : answers) {
        scores[1] = (eachAnswer == *firstIter ? scores[1] + 1 : scores[1]);
        scores[0] = (scores[1] > scores[0] ? scores[1] : scores[0]);
        
        scores[2] = (eachAnswer == *secondIter ? scores[2] + 1 : scores[2]);
        scores[0] = (scores[2] > scores[0] ? scores[2] : scores[0]);
        
        scores[3] = (eachAnswer == *thirdIter ? scores[3] + 1 : scores[3]);
        scores[0] = (scores[3] > scores[0] ? scores[3] : scores[0]);
        
        firstIter = (firstIter == first.end() - 1 ? first.begin() : firstIter + 1);
        secondIter = (secondIter == second.end() - 1 ? second.begin() : secondIter + 1);
        thirdIter = (thirdIter == third.end() - 1 ? third.begin() : thirdIter + 1);
    }
    
    for(int i = 1; i < scores.size(); i++) {
        if(scores[i] == scores[0]) {
            answer.push_back(i);
        }
    }
    
    return answer;
}
