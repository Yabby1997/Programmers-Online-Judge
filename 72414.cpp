#include <string>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

int timeToSeconds(string time) {
    int hours = stoi(string(time.begin(), time.begin() + 2));
    int minutes = stoi(string(time.begin() + 3, time.begin() + 5));
    int seconds = stoi(string(time.begin() + 6, time.begin() + 8));
    
    return hours * 3600 + minutes * 60 + seconds;
}

void logToTimes(vector<int>& seconds, string log) {
    int from = timeToSeconds(string(log.begin(), log.begin() + 8));
    int to = timeToSeconds(string(log.begin() + 9, log.end()));
    
    while(from < to) {
        seconds[from] += 1;
        from++;
    }
}

string timeToString(int time) {
    int hours = time / 3600;
    int minutes = (time - hours * 3600) / 60;
    int seconds = time - (hours * 3600) - (minutes * 60);
    
    char tempString [9];
    sprintf(tempString, "%02d:%02d:%02d", hours, minutes, seconds);
    
    return string(tempString);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int endTime = timeToSeconds(play_time);
    int advTime = timeToSeconds(adv_time);
    vector<int> seconds(endTime, 0);
    
    for(string log : logs) {
        logToTimes(seconds, log);
    }
    
    long long bestSum = 0;
    int bestFrom = 0;
    
    long long sum = 0;
    int from = 0;
    int to = advTime;
    
    queue<int> searchQueue;
    
    for(int i = 0; i <= to; i++) {
        searchQueue.push(seconds[i]);
        sum += seconds[i];
    }
    bestSum = sum;
    
    while(to <= endTime) {
        sum -= searchQueue.front();
        sum += seconds[to];
        
        from++;
        searchQueue.pop();
        to++;
        searchQueue.push(seconds[to]);
        
        if(sum > bestSum) {
            bestSum = sum;
            bestFrom = from;
        }
    }
    
    return timeToString(bestFrom);
}
