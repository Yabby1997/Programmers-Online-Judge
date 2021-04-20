#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define INF 200000000

using namespace std;

vector<int> numOfConversionsForWord;
vector<vector<int>> adjacencyList;
vector<string> allWords;
int indexOfTargetWord = -1;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // begin과 words를 모두 포함하는 allWords생성
    allWords.push_back(begin);
    for(int i = 0; i < words.size(); i++) {
        allWords.push_back(words[i]);
        
        if(words[i] == target) {
            indexOfTargetWord = i + 1;
        }
    }
    
    if(indexOfTargetWord == -1) {
        return 0;
    }
    
    // 모든 단어에 대해 몇번의 변환 필요한지를 기록할 벡터 numOfConversionsForWord생성.
    numOfConversionsForWord = vector<int>(words.size() + 1, INF);
    numOfConversionsForWord[0] = 0;
    
    // 모든 단어들에 대해서 연결여부 확인, 그로부터 인접리스트, adjacencyList를 만들기. 
    adjacencyList = vector<vector<int>>(words.size() + 1, vector<int>());
    
    for(int i = 0; i < allWords.size(); i++) {
        for(int j = i + 1; j < allWords.size(); j++) {
            int difference = 0;
            for(int k = 0; k < allWords[i].size(); k++) {
                if(allWords[i][k] != allWords[j][k]) {
                    difference += 1;
                }
            }
            if(difference == 1) {
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
            }
        }
    }
    
    // 만들어진 인접리스트를 기반으로, begin에서부터 BFS를 돌린다.
    queue<int> edgeQueue;
    edgeQueue.push(0);
    while(!edgeQueue.empty()) {
        int current = edgeQueue.front();
        edgeQueue.pop();
        
        for(auto to : adjacencyList[current]) {
            if(numOfConversionsForWord[to] > numOfConversionsForWord[current] + 1) {
                numOfConversionsForWord[to] = numOfConversionsForWord[current] + 1;
                edgeQueue.push(to);
            }
        }
    }
    
    // 얻어온 값이 임계값을 넘겼다면 도달불가능, 아니라면 도달가능이니 이에 알맞는 값을 넘겨준다.
    return numOfConversionsForWord[indexOfTargetWord] == INF ? 0 : numOfConversionsForWord[indexOfTargetWord];
}
