#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, string> referralTable;
unordered_map<string, int> profitTable;

void propagateProfit(string salesman, int profit) {
    int profitToPropagate = profit / 10;
    int profitToPreserve = profit - profitToPropagate;
    string propagationTarget = referralTable[salesman];
    
    profitTable[salesman] += profitToPreserve;
    
    if(propagationTarget != "-" && profitToPropagate > 0) propagateProfit(referralTable[salesman], profitToPropagate);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); i++) referralTable[enroll[i]] = referral[i];
    
    for(int i = 0; i < seller.size(); i++) {
        string salesman = seller[i];
        int profit = amount[i] * 100;
        propagateProfit(salesman, profit);
    }
    
    for(auto eachSalesman : enroll) answer.push_back(profitTable[eachSalesman]);
    
    return answer;
}
