#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> adjacencyList;
vector<string> answer;
bool found = false;

void DFS(string currentAirport, unordered_map<string, vector<bool>> ticketUse, vector<string> ticketLog, int remainingTickets);

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<bool>> ticketUse;
    int numOfRemainingTickets = tickets.size();
    
    for(auto ticket : tickets) {
        adjacencyList[ticket[0]].push_back(ticket[1]);
        ticketUse[ticket[0]].push_back(false);
    }
    
    for(auto i = adjacencyList.begin(); i != adjacencyList.end(); i++) {
        sort(i->second.begin(), i->second.end(), [](string a, string b) { return a < b; });
    }
    
    DFS("ICN", ticketUse, vector<string>(), tickets.size());

    return answer;
}


void DFS(string currentAirport, unordered_map<string, vector<bool>> ticketUse, vector<string> ticketLog, int remainingTickets){
    if(found) return;
    
    ticketLog.push_back(currentAirport);
    
    if(remainingTickets == 0) {
        answer = ticketLog;
        found = true;
        return;
    }
    
    if(all_of(ticketUse[currentAirport].begin(), ticketUse[currentAirport].end(), [](bool a){ return a; })) {
        return;
    }
    
    for(int i = 0; i < ticketUse[currentAirport].size(); i++) {
        if(!ticketUse[currentAirport][i]) {
            ticketUse[currentAirport][i] = true;
            DFS(adjacencyList[currentAirport][i], ticketUse, ticketLog, remainingTickets - 1);
            ticketUse[currentAirport][i] = false;
        }
    }
}
