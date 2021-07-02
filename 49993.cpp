#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> skillTable;
    
    for(int i = 0; i < skill.size(); i++) skillTable[skill[i]] = i;
    
    for(auto eachSkillTree : skill_trees) {
        int treeLevel = 0;
        
        for(int i = 0; i < eachSkillTree.size(); i++) {
            if(skillTable.find(eachSkillTree[i]) == skillTable.end()) continue;
            if(skillTable[eachSkillTree[i]] == treeLevel) treeLevel++;
            else {
                answer--;
                break;
            }
        }
        answer++;
    }
    
    return answer;
}
