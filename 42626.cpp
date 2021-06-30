#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare {
    bool operator() (int lhs, int rhs) {
        return lhs > rhs;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, compare> minHeap;
    
    for(auto each : scoville) minHeap.push(each);
    
    while(true) {
        if(minHeap.empty()) return -1;
        
        int minimum = minHeap.top();
        if(minimum >= K) break ;
        
        minHeap.pop();
        if(minHeap.empty()) return -1;
        
        int secondMinimum = minHeap.top();
        minHeap.pop();
        
        minHeap.push(minimum + 2 * secondMinimum);
        answer++;
    }
    
    return answer;
}
