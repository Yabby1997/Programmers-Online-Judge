#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> toNbitBinary(int n, int number) {
    list<int> binary;
    
    while(true) {
        binary.push_front(number % 2);
        number = number / 2;
        
        if(number <= 1) {
            binary.push_front(number);
            break;
        }
    }
    
    for(int i = binary.size(); i < n; i++) binary.push_front(0);
    
    return vector(binary.begin(), binary.end());
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        string result = "";
        vector<int> row1 = toNbitBinary(n, arr1[i]);
        vector<int> row2 = toNbitBinary(n, arr2[i]);
        for(int j = 0; j < n; j++) {
            if(row1[j] || row2[j]) result += '#';
            else result += ' ';
        }
        answer.push_back(result);
    }
    
    return answer;
}
