#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first{1, 2, 3, 4, 5};
    vector<int> second{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int firstScore = 0;
    int secondScore = 0;
    int thirdScore = 0;
    int bestScore = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(first[i % first.size()] == answers[i])
            firstScore++;
        if(second[i % second.size()] == answers[i])
            secondScore++;
        if(third[i % third.size()] == answers[i])
            thirdScore++;
    }
    
    if(bestScore < firstScore)
        bestScore = firstScore;
    if(bestScore < secondScore)
        bestScore = secondScore;
    if(bestScore < thirdScore)
        bestScore = thirdScore;
    
    if(bestScore == firstScore)
        answer.push_back(1);
    if(bestScore == secondScore)
        answer.push_back(2);
    if(bestScore == thirdScore)
        answer.push_back(3);
    
    return answer;
}
