#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool intCompare(int left, int right) { 
    return left > right;
}

int solution(int n, vector<vector<int>> edge) {
    vector<int> costs = vector<int>(n + 1, 200000);
    vector<int> farthestCosts;
    vector<vector<int>> adjacencyList = vector<vector<int>>(n + 1, vector<int>{});
    
    for(auto each: edge) {
        adjacencyList[each[0]].push_back(each[1]);
        adjacencyList[each[1]].push_back(each[0]);
    }
    
    queue<int> vertexQueue;
    vertexQueue.push(1);
    costs[1] = 0;
    
    while(!vertexQueue.empty()) {
        int current = vertexQueue.front();
        vertexQueue.pop();
        
        for(auto each: adjacencyList[current]) {
            if(costs[each] > costs[current] + 1) {
                costs[each] = costs[current] + 1;
                vertexQueue.push(each);
            }
        }
    }
    
    sort(costs.begin(), costs.end(), intCompare);
    copy_if(costs.begin(), costs.end(), std::back_inserter(farthestCosts), [costs](int i) { return i == costs[1]; });
    
    return farthestCosts.size();
}
