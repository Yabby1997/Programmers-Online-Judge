#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> answerSet;
    
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            answerSet.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer = vector(answerSet.begin(), answerSet.end());
    
    return answer;
}
