#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define INF 200000000

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> temp(n + 1, vector<bool>(n + 1, false));
    
    for(int i = 1; i <= n; i++) {
        win[i][i] = true;
    }
    
    for(auto result : results) {
        win[result[1]][result[0]] = true;
        temp[result[0]][result[1]] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j != i && win[j][i]) {
                for(int k = 1; k <= n; k++) {
                    if(win[i][k]) {
                        win[j][k] = true;
                        temp[k][j] = true;
                    }
                }
            }
        }
    }
    
    for(int i = 1; i < win.size(); i++) {
        for(int j = 1; j < win[i].size(); j++) {
            win[i][j] = win[i][j] | temp[i][j];
        }
    }
    
    for(auto each : win) {
        cout<<endl;
        if(all_of(each.begin() + 1, each.end(), [](bool a) { return a; })) answer++;
    }
    
    return answer;
}
