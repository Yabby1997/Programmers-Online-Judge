#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });
    
    for(int i = 0; i < citations.size(); i++) {
        int h = i + 1;
        if(citations[i] >= h) {
            if(h >= citations.size() || citations[h] <= h) {
                answer = h;
            }
        }
    }
    
    return answer;
}
