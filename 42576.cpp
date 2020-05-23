#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i = 0; i < participant.size(); i++){
        if(i == completion.size()){
            answer = participant.at(i);
            break;
        }
        if(participant.at(i) != completion.at(i)){
            answer = participant.at(i);
            break;
        }
    }
    return answer;
}
