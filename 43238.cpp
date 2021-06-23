#include <string>
#include <vector>

#define MAX 100000000000000

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long from = 0;
    long long to = MAX;
    long long mid = (long long)((from + to) / 2);
    while(true) {
        if(from == to) return from;
        
        long long processed = 0;
        for(auto each : times) {
            processed += (long long)(mid / each);
        }
        if(processed >= n) {
            to = mid;
            mid = (long long)((from + to) / 2);
        } else {
            from = mid + 1;
            mid = (long long)((from + to) / 2);
        }
    }
    return answer;
}
