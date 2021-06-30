#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

#define INITIAL 540

using namespace std;

int toMinutes(string formatted) {
    return stoi(formatted.substr(0, 2)) * 60 + stoi(formatted.substr(3));
}

string toTime(int timeInMinutes) {
    string timeString;
    
    int hours = timeInMinutes / 60;
    int minutes = timeInMinutes % 60;
    
    char temp[3];
    snprintf(temp, sizeof(temp), "%02d", hours);
    timeString += string(temp) + ":";
    snprintf(temp, sizeof(temp), "%02d", minutes);
    timeString += string(temp);
    
    return timeString;
}

string solution(int n, int t, int m, vector<string> timetable) {
    deque<int> minutes;
    int shuttleTime = INITIAL;
    int last = INITIAL + 1;
    
    for(string time : timetable) {
        int timeInMinutes = toMinutes(time);
        minutes.push_back(timeInMinutes);
    }
    
    sort(minutes.begin(), minutes.end());
    
    // 셔틀은 n회 운행한다.
    for(int i = 0; i < n; i++) {
        // 한번에 m명까지 탑승 가능하다.
        for(int j = 0; j < m; j++) {
            // 더 탑승 가능한데 대기열이 없다면, 마지막 셔틀을 타도 된다.
            if(minutes.empty()) return toTime(INITIAL + t * (n - 1));
            
            // 더 탑승 가능하고 탑승 가능한 대기자가 있다면, 대기자를 탑승시키고, 그 보다 1분 먼저 탈 수 있는 시간을 기록한다.
            // 더 탑승 가능한데 탑승 가능한 대기자가 없다면, 셔틀이 도착하는시간을 기록한다.
            int minute = minutes.front();
            if(minute <= shuttleTime) {
                minutes.pop_front();
                last = minute - 1;
            } else {
                last = shuttleTime;
            }
        }
        // 셔틀은 t분 간격으로 도착한다.
        shuttleTime += t;
    }
    
    return toTime(last);
}
