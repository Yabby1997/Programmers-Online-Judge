#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

int INF = 200000000;
int numOfVertices = 0;
int startingVertex = 0;
int destinationA = 0;
int destinationB = 0;
vector<vector<pair<int, int>>> adjacencyList(201, vector<pair<int, int>>());
priority_queue<pair<int, int>> edgeQueue;

vector<int> dijkstra(int from);

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    numOfVertices = n;
    startingVertex = s;
    destinationA = a;
    destinationB = b;
    
    for(int i = 0; i < fares.size(); i++) {
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];  
        
        adjacencyList[from].push_back(make_pair(cost, to));
        adjacencyList[to].push_back(make_pair(cost, from));
    }
    
    vector<int> totalCost = dijkstra(startingVertex);
    for(int i = 1; i <= numOfVertices; i++) {
        vector<int> cost = dijkstra(i);
        totalCost[i] = totalCost[i] + cost[destinationA] + cost[destinationB];
    }
    answer = *min_element(totalCost.begin(), totalCost.end());
    
    return answer;
}

vector<int> dijkstra(int from) {
    vector<int> costs(numOfVertices + 1, INF);
    edgeQueue.push(make_pair(0, from));
    costs[from] = 0;
    
    while(!edgeQueue.empty()) {
        pair<int, int> current = edgeQueue.top();
        edgeQueue.pop();
        int currentCost = -current.first;
        int currentFrom = current.second;
        
        if(costs[currentFrom] < currentCost) {
            continue;
        }
        
        for(int i = 0; i < adjacencyList[currentFrom].size(); i++) {
            pair<int, int> next = adjacencyList[currentFrom][i];
            int nextCost = -currentCost - next.first;
            int to = next.second;
            
            if(-nextCost < costs[to]) {
                costs[to] = -nextCost;
                edgeQueue.push(make_pair(nextCost, to));
            }
        }
    }
    
    return costs;
}
