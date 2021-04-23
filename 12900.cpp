#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> tiles(60001, 1);

int solution(int n) {
    int answer = 0;
    
    if(n > 1) {
        for(int i = 2; i <= n; i++) {
            tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 1000000007;
        }
    }
    
    answer = tiles[n];
    
    return answer;
}
