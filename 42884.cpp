#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct route {
    int from;
    int to;
};

auto compare = [](route& a, route& b) {
    return a.from > b.from;
};

priority_queue<route, vector<route>, decltype(compare)> sorted(compare);

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    for(int i = 0; i < routes.size(); i++) {
        sorted.push(route{routes[i][0], routes[i][1]});
    }
    
    int from = -35000;
    int to = 35000;
    while(!sorted.empty()) {
        route current = sorted.top();
        sorted.pop();
        
        if(current.from > to) {
            answer += 1;
            from = current.from;
            to = current.to;
        } else {
            from = current.from;
            to = current.to < to ? current.to : to;
        }
    }
    answer += 1;
    
    return answer;
}
