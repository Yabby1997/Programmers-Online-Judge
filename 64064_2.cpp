#include <string>
#include <vector>
#include <set>

using namespace std;

vector<bool> visited(8, false);
set<string> candidates;

bool isCandidate(string a, string b){
    if(a.length() != b.length())
        return false;
    for(int i =0; i <a.length(); i++)
        if(a[i] != b[i] && b[i] != '*')
            return false;
    return true;
}

void dfs(int depth, vector<string> user_id, vector<string>& banned_id){
    if(depth == banned_id.size()){
        string temp;
        
        for(int i =0; i < user_id.size(); i++)
            if(visited[i]) temp += to_string(i);
        
        if(candidates.find(temp) == candidates.end())
            candidates.insert(temp);
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++) {
        if(!visited[i] && isCandidate(user_id[i], banned_id[depth])) {
            visited[i] = true;
            dfs(depth+1, user_id, banned_id);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, user_id, banned_id);
    return candidates.size();
}
