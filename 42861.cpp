#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct edge {
    int to;
    int cost;
};

struct compare {
    bool operator()(const edge& a, edge& b) {
        return a.cost > b.cost;
    }  
};

vector<vector<edge>> adjacencyList;
priority_queue<edge, vector<edge>, compare> edgeQueue;
vector<bool> visited;

void visit(int node);

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    adjacencyList = vector<vector<edge>>(n, vector<edge>());
    visited = vector<bool>(n, false);
    
    for(int i = 0; i < costs.size(); i++) {
        adjacencyList[costs[i][0]].push_back(edge{costs[i][1], costs[i][2]});
        adjacencyList[costs[i][1]].push_back(edge{costs[i][0], costs[i][2]});
    }
    
    visit(0);
    while(true) {
        edge closest = edgeQueue.top();
        edgeQueue.pop();
        
        if(visited[closest.to]) continue;
        
        answer += closest.cost;
        visit(closest.to);
        
        if(all_of(visited.begin(), visited.end(), [](bool each){return each;})) break;
    }
    return answer;
}

void visit(int node) {
    while(!adjacencyList[node].empty()) {
        edgeQueue.push(adjacencyList[node].back());  
        adjacencyList[node].pop_back();
    }
    visited[node] = true;
}
