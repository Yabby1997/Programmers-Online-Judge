#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    vector<bool> pickVector(numbers.size(), false);
    vector<int> candidates;
    
    // 모든 수의 조합만들기
    for(int i = numbers.size() - 1; i >= 0; i--) {
        pickVector[i] = true;
        do {
            vector<int> pickedIndices;
            for(int j = 0; j < pickVector.size(); j++) {
                if(pickVector[j]) pickedIndices.push_back(j);
            }
            
            do {
                string combination = "";
                for(auto pickedIndex : pickedIndices) {
                    combination += numbers[pickedIndex];
                }
                candidates.push_back(stoi(combination));
            } while(next_permutation(pickedIndices.begin(), pickedIndices.end()));
        } while(next_permutation(pickVector.begin(), pickVector.end()));
    }
    
    // 중복되는 수 제거
    sort(candidates.begin(), candidates.end());
    auto it = unique(candidates.begin(), candidates.end());
    candidates.resize(distance(candidates.begin(), it));
    unique(candidates.begin(), candidates.end(), [](int a, int b){ return a == b; });
    
    // 수 중 소수 카운트
    for(auto candidate : candidates) {
        if(candidate == 0 || candidate == 1) continue;
        int i = 2;
        while(true) {
            if(i > sqrt(candidate)) { 
                answer ++;
                break;
            }
            if(candidate % i == 0) break;
            i++;
        }
    }
    
    return answer;
}
