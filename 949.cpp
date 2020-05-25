#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long square(long long n){
    return n * n;
}

long long solution(long long n) {
    long long rooted = sqrt(n);
    if(square(rooted) == n){
        return square(rooted + 1);
    }
    return -1;
}
