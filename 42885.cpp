#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int lightPointer = 0; 
    int heavyPointer = people.size() - 1;
    
    while(lightPointer < heavyPointer) {
        if(people[lightPointer] + people[heavyPointer] <= limit) {
            answer++;
            lightPointer++;
            heavyPointer--;
        } else if(people[heavyPointer] <= limit) {
            answer++;
            heavyPointer--;
        } else if(people[lightPointer] + people[lightPointer + 1] <= limit) {
            answer++;
            lightPointer += 2;
        }
    }
    
    answer = answer + heavyPointer - lightPointer + 1;
    
    return answer;
}
