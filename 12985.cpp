#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    
    while(a != b) {
        a = (a / 2) + ((a % 2 != 0) ? 1 : 0);
        b = (b / 2) + ((b % 2 != 0) ? 1 : 0);
        
        answer++;
    }

    return answer;
}
