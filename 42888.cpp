#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

unordered_map<string, string> profile;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> commands;
    
    // 단순 문자열 record를 파싱하여 {행위, 유저아이디, 닉네임} 혹은, {행위, 유저아이디} 구조의 commands로 만듬
    for(auto each : record) {
        vector<string> command;
        
        stringstream ss(each);
        string temp;
        while (ss >> temp) command.push_back(temp);
        
        commands.push_back(command);
    }
    
    // 파싱된 commands를 사용해 유저아이디에 해당하는 닉네임을 갱신해준다.
    for(auto command : commands) {
        if(command[0] == "Enter" || command[0] == "Change") {
            profile[command[1]] = command[2];
        }
    }

    // 파싱된 commands를 사용해 메시지를 출력한다. 최종적으로 갱신된 닉네임으로 표시되어야한다.
    for(auto command : commands) {
        string notificationString = profile[command[1]];
        
        if(command[0] == "Enter") {
            notificationString +="님이 들어왔습니다.";
        } else if(command[0] == "Leave") {
            notificationString +="님이 나갔습니다.";
        } else {
            continue;
        }
        answer.push_back(notificationString);
    }
    
    return answer;
}
