#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));
    for(auto puddle : puddles) map[puddle[0]][puddle[1]] = -1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == -1) continue;
            if(i == 1) map[i][j] = map[i][max(j - 1, 0)] == -1 ? -1 : 1;
            else if(j == 1) map[i][j] = map[max(i - 1, 0)][j] == -1 ? -1 : 1;
            else {
                if(map[i - 1][j] == -1 && map[i][j - 1] == -1) map[i][j] = -1;
                else map[i][j] = (max(map[i - 1][j], 0) + max(map [i][j - 1], 0)) % 1000000007;
            }
        }
    }
    
    return map[m][n] == -1 ? 0 : map[m][n];
}
