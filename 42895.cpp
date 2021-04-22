#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> numbers(32001, -1);
vector<vector<int>> calculated(9, vector<int>());

int solution(int N, int number) {
    int answer = 0;
    
    numbers[N] = 1;
    calculated[1].push_back(N);
    
    for(int i = 2; i <= 8; i++) {
        int append = 0;
        for(int j = 0; j < i; j++) {
            append = append * 10 + N;
        }
        if(append >= 0 && append <= 32000 && (numbers[append] == -1 || numbers[append] > i)) {
            calculated[i + 1].push_back(append);
            numbers[append] = i; 
            calculated[i].push_back(append);
        }
        
        for(int j = 1; j <= i; j++) {
            for(auto eachSmaller : calculated[j]){
                for(auto eachBigger : calculated[i - j]) {
                    
                    int plus = eachSmaller + eachBigger;
                    if(plus >= 0 && plus <= 32000 && (numbers[plus] == -1 || numbers[plus] > i)) {
                        calculated[i].push_back(plus);
                        numbers[plus] = i;
                    }

                    int minus = eachSmaller - eachBigger;
                    if(minus >= 0 && minus <= 32000 && (numbers[minus] == -1 || numbers[minus] > i)) {
                        calculated[i].push_back(minus);
                        numbers[minus] = i;
                    }

                    int minus2 = eachBigger - eachSmaller;
                    if(minus2 >= 0 && minus2 <= 32000 && (numbers[minus2] == -1 || numbers[minus2] > i)) {
                        calculated[i].push_back(minus2);
                        numbers[minus2] = i;
                    }

                    int mul = eachSmaller * eachBigger;
                    if(mul >= 0 && mul <= 32000 && (numbers[mul] == -1 || numbers[mul] > i)) {
                        calculated[i].push_back(mul);
                        numbers[mul] = i;
                    }

                    if(eachBigger != 0) {
                        int div = int(floor(eachSmaller / eachBigger));
                        if(div >= 0 && div <= 32000 && (numbers[div] == -1 || numbers[div] > i)) {
                            calculated[i].push_back(div);
                            numbers[div] = i;
                        }
                    }

                    if(eachSmaller != 0) {
                        int div2 = int(floor(eachBigger / eachSmaller));
                        if(div2 >= 0 && div2 <= 32000 && (numbers[div2] == -1 || numbers[div2] > i)) {
                            calculated[i].push_back(div2);
                            numbers[div2] = i;
                        }
                    }
                }
            }
        }
    }
    
    return numbers[number];
}
