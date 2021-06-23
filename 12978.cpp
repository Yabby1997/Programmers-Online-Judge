#include <iostream>
#include <vector>
#include <queue>

#define INF 200000000

using namespace std;

struct Edge {
    int to;
    int timeToDeliver;
};

auto compare = [](Edge lhs, Edge rhs) {
    return lhs.timeToDeliver > rhs.timeToDeliver;
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<Edge>> adjacencyList(N + 1, vector<Edge>());
    vector<int> timeToDeliverToEachTown(N + 1, INF);
    
    for(auto edge : road) {
        int from = edge[0];
        int to = edge[1];
        int timeToDeliver = edge[2];
        
        adjacencyList[from].push_back(Edge{to, timeToDeliver});
        adjacencyList[to].push_back(Edge{from, timeToDeliver});
    }
    
    timeToDeliverToEachTown[1] = 0;
    priority_queue<Edge, vector<Edge>, decltype(compare)> townQueue(compare);
    townQueue.push(Edge{1, 0});
    
    while(!townQueue.empty()) {
        auto edge = townQueue.top();
        townQueue.pop();
        int from = edge.to;
        int spentTime = timeToDeliverToEachTown[from];
        
        for(auto each : adjacencyList[from]) {
            int to = each.to;
            int timeToDeliver = each.timeToDeliver + spentTime;
            
            if(timeToDeliver < timeToDeliverToEachTown[to]) {
                timeToDeliverToEachTown[to] = timeToDeliver;
                townQueue.push(each);
            }
        }
    }
    
    for(auto each : timeToDeliverToEachTown) answer += each <= K ? 1 : 0;
    
    return answer;
}
