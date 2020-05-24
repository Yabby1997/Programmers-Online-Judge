#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int size, int target, int currentValue, int index){
    if(index == size)
        if(currentValue == target)  return 1;
        else return 0;
        
    return  dfs(numbers, size, target, currentValue + numbers.at(index), index + 1) + 
            dfs(numbers, size, target, currentValue - numbers.at(index), index + 1);
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    return dfs(numbers, size, target, 0, 0);
}
