#include <string>
#include <vector>
#include <iostream>

using namespace std;

int toSeconds(string time) {
    return stoi(string(time.begin(), time.begin() + 2)) * 3600 + stoi(string(time.begin() + 3, time.begin() + 5)) * 60 + stoi(string(time.begin() + 6, time.end()));
}

string toString(int time) {
    int hours = time / 3600;
    int minutes = (time - hours * 3600) / 60;
    int seconds = (time - hours * 3600) - minutes * 60;
    char tempString[9];
    sprintf(tempString, "%02d:%02d:%02d", hours, minutes, seconds);
    
    return tempString;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playTime = toSeconds(play_time);
    int adTime = toSeconds(adv_time);
    vector<long long> accumulatedViews = vector<long long>(playTime + 1, 0);
    vector<int> checkingPoints;
    
    for(auto log: logs) {
        int from = toSeconds(string(log.begin(), log.begin() + 8));
        int to = toSeconds(string(log.begin() + 9, log.end()));
        
        accumulatedViews[from] += 1;
        accumulatedViews[to] -= 1;
        
        checkingPoints.push_back(from);
        if(to - adTime > 0) { checkingPoints.push_back(to - adTime); }
    }
    
    for(int i = 1; i <= playTime; i++) { accumulatedViews[i] += accumulatedViews[i - 1]; }
    for(int i = 1; i <= playTime; i++) { accumulatedViews[i] += accumulatedViews[i - 1]; }
    
    long long bestViews = accumulatedViews[adTime - 1];
    int bestTime = 0;
    for(auto checkingPoint: checkingPoints) {
        long long currentViews = accumulatedViews[min(playTime, checkingPoint + adTime - 1)] - accumulatedViews[checkingPoint - 1];
        
        if(currentViews > bestViews || (currentViews == bestViews && bestTime > checkingPoint)) {
            bestViews = currentViews;
            bestTime = checkingPoint;
        }
    }
    
    return toString(bestTime);
}
