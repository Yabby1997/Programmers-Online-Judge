#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> memo(2001, 0);

long long calcRecursively(int n) {
    if(memo[n] != 0) return memo[n];
    else return memo[n] = (calcRecursively(n - 1) + calcRecursively(n - 2)) % 1234567;
}

long long solution(int n) {
    for(int i = 1; i < 3; i++) memo[i] = i;   
    
    return calcRecursively(n);
}


