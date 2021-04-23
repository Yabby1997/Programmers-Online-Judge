#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    vector<int> finishedTimes;
    vector<int> startedTimes;
    int biggestTraffic = 0;

    for(int i = 0; i < lines.size(); i++) {
        string line = lines[i];
        int h = stoi(string(line.begin() + 11, line.begin() + 13)) * 3600 * 1000;
        int m = stoi(string(line.begin() + 14, line.begin() + 16)) * 60 * 1000;
        int s = stoi(string(line.begin() + 17, line.begin() + 19)) * 1000;
        int ms = stoi(string(line.begin() + 20, line.begin() + 23));
        double d = stod(string(line.begin() + 24, line.end() - 1));
        
        int finishedTime = h + m + s + ms;
        int startedTime = finishedTime - (1000 * d) + 1;
        
        finishedTimes.push_back(finishedTime);
        startedTimes.push_back(startedTime);
    }
    
    for(int i = 0; i < finishedTimes.size(); i++) {
        int from = finishedTimes[i];
        int to = from + 999;
        
        int traffic = 0;
        for(int j = 0; j < startedTimes.size(); j++) {
            if(finishedTimes[j] <= to && finishedTimes[j] >= from) {
                traffic += 1;
            } else if(startedTimes[j] <= to && finishedTimes[j] >= from) {
                traffic += 1;
            }
        }
        biggestTraffic = biggestTraffic < traffic ? traffic : biggestTraffic;
    }

    return biggestTraffic;
}
