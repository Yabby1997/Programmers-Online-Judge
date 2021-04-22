#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int n = 1;
    int m = 200000000;
    
    while(true) {
        if(yellow % n == 0) {
            m = yellow / n;
            
            if(n * 2 + m * 2 + 4 == brown) {
                answer.push_back(m + 2);
                answer.push_back(n + 2);
                break;
            }
        }
        n++;
        
        if(n >= m) break;
    }
    
    return answer;
}

