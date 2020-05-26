#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    deque<int> bridge(bridge_length, 0);
    int count = 0;
    int arrivalCount = 0;
    int currentWeight = 0;
    
    int index = 0;
    while(arrivalCount != truck_weights.size()){
        int departure = truck_weights[index];
        int arrival = bridge.front();
        
        bridge.pop_front();
        if(arrival != 0){
            arrivalCount++;
            currentWeight -= arrival;
        }
        if(currentWeight + truck_weights[index] <= weight){
            currentWeight += departure;
            bridge.push_back(departure);
            index++;
        }
        else{
            bridge.push_back(0);
        }
        count++;
    }
    return count;
}
