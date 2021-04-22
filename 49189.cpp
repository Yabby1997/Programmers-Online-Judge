#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> adjacencyList(n + 1, vector<int>());
    vector<int> distances(n + 1, 200000000);
    int longestDistance = 0;
    queue<int> vertexQueue;
    
    for(auto each : edge) {
        adjacencyList[each[0]].push_back(each[1]);
        adjacencyList[each[1]].push_back(each[0]);
    }
    
    distances[1] = 0;
    vertexQueue.push(1);
    while(!vertexQueue.empty()) {
        int current = vertexQueue.front();
        vertexQueue.pop();
        
        for(int to : adjacencyList[current]) {
            if(distances[to] > distances[current] + 1) {
                distances[to] = distances[current] + 1;
                vertexQueue.push(to);
                longestDistance = longestDistance < distances[to] ? distances[to] : longestDistance;
            }
        }
    }
    
    for(auto distance : distances) {
        if(distance == longestDistance) answer++;
    }
    
    return answer;
}
