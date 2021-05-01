#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0; i < answer.size() - 1; i++) {
        for(int j = i + 1; j < answer.size(); j++) {
            if(prices[j] < prices[i]) {
                answer[i] = j - i;
                break;
            }
            if(j == answer.size() - 1) {
                answer[i] = j - i;
            }
        }
    }
    
    return answer;
}
