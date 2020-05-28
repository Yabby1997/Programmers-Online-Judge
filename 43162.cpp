#include <string>
#include <vector>
#include <algorithm>

#include<iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int length = computers.size();
    int answer = length;
    vector<int> network;
    
    for(int i = 0; i < length; i++){
        network.push_back(i);
    }
    
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(computers[i][j] == 1){
                if(network[i] != network[j]){
                    int target = network[i];
                    replace(network.begin(), network.end(), target, network[j]);
                }
            }
        }
    } 
    sort(network.begin(), network.end());
    network.erase(unique(network.begin(), network.end()), network.end());
    
    return network.size();
}
