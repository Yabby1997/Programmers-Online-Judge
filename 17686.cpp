#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <iterator>

using namespace std;

struct compare {
    bool operator() (pair<int, long long> lhs, pair<int, long long> rhs) {
        return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first > rhs.first);
    }  
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    set<string> headers;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> fileQueue;
    
    // 먼저 header 를 모두 set에 넣어 정렬되도록 해준다. header가 정렬되면 set의 시작점부터 해당 header의 거리를 가지고 우선순위를 알 수 있다.
    for(int i = 0; i < files.size(); i++) {
        string file = files[i];
        
        transform(file.begin(), file.end(), file.begin(), ::toupper);
        string header = file.substr(0, file.find_first_of("0123456789"));
        headers.insert(header);
    }
    
    // header의 우선순위에 100000를 곱해주는 이유는, 뒤에 붙는 숫자가 최대 99999이기때문이다. 그렇게 인덱스와 우선순위를 pair로 엮어 우선순위 큐에 넣는다.
    for(int i = 0; i < files.size(); i++) {
        string file = files[i];
        
        transform(file.begin(), file.end(), file.begin(), ::toupper);
        int numberFrom = file.find_first_of("0123456789");
        int numberTo = file.find_last_of("0123456789");
        
        string header = file.substr(0, numberFrom);
        int number = stoi(file.substr(numberFrom, numberTo - numberFrom + 1));
        
        auto it = headers.find(header);
        int distanceFromSet = distance(headers.begin(), it);
        
        long long score = distanceFromSet * 100000 + number;
        fileQueue.push(make_pair(i, score));
    }
    
    // 우선순위 큐는 우선순위가 높은것 (second 가 낮은것) 을 우선적으로 뽑아준다. 이 때 만약 동일한 우선순위가 있다면, 인덱스가 낮은것 (first가 낮은것) 을 우선적으로 뽑아준다. 그렇게 순서대로 뽑힌 인덱스에 해당하는 파일명을 answer에 넣어준다.
    while(!fileQueue.empty()) {
        auto top = fileQueue.top();
        fileQueue.pop();
        answer.push_back(files[top.first]);
    }
    
    return answer;
}
