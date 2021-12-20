#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int stringTimeToInt(string time) {
    return stoi(string(time.begin(), time.begin() + 2)) * 3600 + stoi(string(time.begin() + 3, time.begin() + 5)) * 60 + stoi(string(time.begin() + 6, time.begin() + 8));
}

string intTimeToString(int time) {
    char temp[9];
    int hours = time / 3600;
    int minutes = (time - hours * 3600) / 60;
    int seconds = (time - hours * 3600) - minutes * 60;
    sprintf(temp, "%02d:%02d:%02d", hours, minutes, seconds);
    return temp;
}

bool compareCandidates(int left, int right) {
    return left < right;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int endTime = stringTimeToInt(play_time);
    int adDuration = stringTimeToInt(adv_time);
    vector<int> viewers = vector<int>(endTime + 1, 0);
    
    auto compareCandidates = [](int left, int right) { return left > right; };
    priority_queue<int, vector<int>, decltype(compareCandidates)> candidates(compareCandidates);
    candidates.push(0);
    
    for(auto log: logs) {
        int starting = stringTimeToInt(string(log.begin(), log.begin() + 8));
        int ending = stringTimeToInt(string(log.begin() + 9, log.begin() + 17));
        for(int playTime = starting; playTime < ending; playTime++) { viewers[playTime] += 1; }
    }
    
    queue<int> views;
    long long bestViewers = 0;
    long long currentViewers = 0;
    int from = 0;
    int to = adDuration;
    int bestTime = 0;
    
    for(int i = from; i < to; i++) {
        currentViewers += viewers[i];
        views.push(viewers[i]);
    }
    bestViewers = currentViewers;
    
    while(to <= endTime) {
        currentViewers += viewers[to];
        currentViewers -= viewers[from];
        views.push(viewers[to]);
        views.pop();
        
        from++;
        to++;
        
        if(currentViewers > bestViewers) {
            bestViewers = currentViewers;
            bestTime = from;
        }
    }
    
    return intTimeToString(bestTime);
}
