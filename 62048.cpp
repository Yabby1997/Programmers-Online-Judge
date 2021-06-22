#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

long long solution(int w,int h) {
    return (long long)w * (long long)h - (w + h - gcd(w, h));
}
