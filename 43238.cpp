#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long from = 0;
    long long to = 100000000000000;
    long long mid = (long long)((from + to) / 2);
    
    while(from < to) {
        long long processed = 0;
        for(auto each : times) processed += (long long)(mid / each);
        
        if(processed >= n) to = mid;
        else from = mid + 1;
        
        mid = (long long)((from + to) / 2);
    }
    
    return from;
}
