#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

struct genre {
    int totalPlays;
    vector<int> indices;
};

auto compareGenres = [](genre& a, genre& b){ return a.totalPlays < b.totalPlays; };

unordered_map<string, vector<int>> genreMap;
priority_queue<genre, vector<genre>, decltype(compareGenres)> genreByPlays(compareGenres);

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        
        if(genreMap.find(genre) != genreMap.end()) {
            genreMap[genre].push_back(i);
        } else {
            genreMap[genre] = vector<int>{i};
        }
    }
    
    for(auto each : genreMap) {
        int totalPlayCount = 0;
        for(auto each : each.second) {
            totalPlayCount += plays[each];
        }
        cout<<endl;
        genreByPlays.push(genre{totalPlayCount, each.second});
    }
    
    while(!genreByPlays.empty()) {
        auto top = genreByPlays.top();
        genreByPlays.pop();
        sort(top.indices.begin(), top.indices.end(), [plays](int a, int b) { return plays[a] > plays[b]; });
        for(int i = 0; i < top.indices.size(); i++) {
            answer.push_back(top.indices[i]);
            if(i == 1) {
                break;
            }
        }
    }
    
    return answer;
}
