#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> gemKinds;
    unordered_map<string, int> visited;
    
    vector<vector<int>> candidates;
    vector<int> answer = {-1, -1};
    
    for(string gem : gems) {
        gemKinds.insert(gem);
    }
    int numOfKinds = gemKinds.size();
    
    int from = 0;
    int to = 0;
    int minLength = 1000000;
    
    while(to < gems.size()) {
        visited[gems[to]]++;
        to++;
        
        if(visited.size() == numOfKinds) {
            while(visited[gems[from]] != 1) {
                visited[gems[from]]--;
                from++;
            }
            visited.erase(gems[from]);
            if(minLength > to - from) {
                minLength = to - from;
                answer[0] = from + 1;
                answer[1] = to;
            }
            from++;
        }
    }
    
    return answer;
}
