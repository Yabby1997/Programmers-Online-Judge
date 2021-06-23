#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int log3(int n) {
    return (int)(log(n) / log(3));
}

void getTernary(int n, vector<int> &ternary) {
    if(n == 0) return;
    int exponent = log3(n);
    ternary[ternary.size() - exponent - 1] += 1;
    getTernary(n - pow(3, exponent), ternary);
}

int solution(int n) {
    int answer = 0;
    vector<int> ternary(log3(n) + 1, 0);
    
    getTernary(n, ternary);
    
    for(int i = 0; i < ternary.size(); i++) answer += pow(3, i) * ternary[i];
    
    return answer;
}
