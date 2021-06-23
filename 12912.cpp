#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    if(a == b) return a;
    else if(a > b) return (((double)a + (double)b) / 2) * (a - b + 1);
    else return (((double)a + (double)b) / 2) * (b - a + 1);
}
