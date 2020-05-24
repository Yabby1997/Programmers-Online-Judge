#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    auto i = lost.begin();
    while(i < lost.end()){
        auto pos = find(reserve.begin(), reserve.end(), *i);
        if(pos != reserve.end()){
            reserve.erase(pos);
            lost.erase(i);
            continue;
        }
        i++;
    }
    
    int answer = n - lost.size();
    
    for(auto i = lost.begin(); i < lost.end(); i++){
        auto pos1 = find(reserve.begin(), reserve.end(), (*i - 1));
        if(pos1 != reserve.end()){
            reserve.erase(pos1);
            answer++;
            continue;
        }
        auto pos2 = find(reserve.begin(), reserve.end(), (*i + 1));
        if(pos2 != reserve.end()){
            reserve.erase(pos2);
            answer++;
        }
    }
    return answer;
}
