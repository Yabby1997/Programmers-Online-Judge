#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> adjacencyList;
vector<string> answer = {"ICN"};

bool DFS(string airport, int remainingTickets) {
    if(remainingTickets == 0) return true;
    
    for(int i = 0; i < adjacencyList[airport].size(); i++) {
        sort(adjacencyList[airport].begin(), adjacencyList[airport].end());
        
        string to = adjacencyList[airport][i];
        adjacencyList[airport].erase(adjacencyList[airport].begin() + i);
        
        answer.push_back(to);
        if(DFS(to, remainingTickets - 1)) return true;
        adjacencyList[airport].push_back(to);
        answer.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for(auto ticket : tickets) {
        string from = ticket[0];
        string to = ticket[1];
        adjacencyList[from].push_back(to);
    }
    
    DFS("ICN", tickets.size());
    
    return answer;
}
