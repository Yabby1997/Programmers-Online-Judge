#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int toRank(int score) {
    switch(score) {
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    unordered_map<int, int> pick;
    int maximum = 0, minimum = 0;
    
    for(int each : lottos) pick[each] += 1;
    
    for(int each : win_nums) {
        if(pick.find(each) != pick.end()) {
            minimum += 1;
            maximum += 1;
        } else if(pick.find(0) != pick.end() && pick[0] > 0) {
            pick[0] -= 1;
            maximum += 1;
        }
    } 
    
    return vector<int>{toRank(maximum), toRank(minimum)};
}
