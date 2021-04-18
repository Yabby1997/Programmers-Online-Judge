#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int length = number.size();
    int from = 0;
    int to = k;
    
    while(true) {
        int selectedIndex = from;
        char selected = '0';
        for(int i = from; i <= to; i++) {
            if(number[i] > selected) {
                selected = number[i];
                selectedIndex = i;
            }
        }
        answer.push_back(selected);
        from = selectedIndex + 1;
        to += 1;
        if(to >= length) {
            break;
        }
    }
    
    cout<<length<<endl;
    
    return answer;
}
