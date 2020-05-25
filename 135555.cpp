#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isNum(char i){
    int val = (int)i;
    
    if(val >= 48 && val <= 57)
        return true;
    return false;
}
bool solution(string s) {
    int size = s.size();
    if(all_of(s.begin(), s.end(), isNum)){
        if(size == 4 || size == 6){
            return true;
        }
    }
    return false;
}
