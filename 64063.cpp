#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> currentNext;

long long find(long long current) {
    if(currentNext.find(current) != currentNext.end()) {
        return currentNext[current] = find(currentNext[current]);
    }
    currentNext[current] = current + 1;
    return current;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    
    for(long long request : room_number) {
        answer.push_back(find(request));
    }
    
    return answer;
}
