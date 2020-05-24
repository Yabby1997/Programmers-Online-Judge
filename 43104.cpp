#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    vector<long> fibonacci{0, 1, 1};
    long long answer = 0;
    for(int i = 3; i <= N; i++){
        fibonacci.push_back(fibonacci.at(i - 2) + fibonacci.at(i - 1));
    }
    answer = fibonacci.at(N) * 2 + (fibonacci.at(N) + fibonacci.at(N - 1)) * 2;
    return answer;
}
