#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> possibleCombinations;

bool isValidCombination(int current){
    for(int i = 0; i < possibleCombinations.size(); i++)
        if((possibleCombinations[i] & current) == possibleCombinations[i])
            return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int rows = relation.size();
    int features = relation[0].size();
    
    for(int combination = 1; combination < (1 << features); combination++){
        if(!isValidCombination(combination))
            continue;
        
        set<string> candidates;
        for(int row = 0; row < rows; row++){
            string candidateString = "";
            for(int pick = 0; pick < features; pick++){
                if(combination & (1 << pick)) 
                    candidateString += relation[row][pick] + "_";
            }
            candidates.insert(candidateString);
        }
        if(candidates.size() == rows)
            possibleCombinations.push_back(combination);
    }
    return possibleCombinations.size();
}
