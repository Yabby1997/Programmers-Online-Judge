#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> estimation;
    
    for(int i = 0; i < progresses.size(); i++){
        estimation.push(ceil((100 - progresses[i]) / speeds[i]));
    }
    
    int task = estimation.front();
    int count = 0;
    while(true){
        if(estimation.empty()){
            answer.push_back(count);
            break;
        }
        if(task >= estimation.front()){
            estimation.pop();
            count++;
            continue;
        }
        task = estimation.front();
        answer.push_back(count);
        count = 0;
    }
    return answer;
}
