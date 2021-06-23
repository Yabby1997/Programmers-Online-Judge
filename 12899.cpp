#include <string>
#include <list>
#include <iostream>

using namespace std;

void solve(int number, list<char> &answer) {
    if(number == 0) return;
    
    int remainder = number % 3;
    answer.push_front(remainder == 0 ? '4' : remainder == 1 ? '1' : '2');
    solve(remainder == 0 ? (number / 3) - 1 : number / 3, answer);
}

string solution(int n) {
    list<char> answerList;
    solve(n, answerList);

    return string(answerList.begin(), answerList.end());
}
