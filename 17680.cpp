#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string toBiggerCase(string request) {
    vector<char> converted;
    for(auto each : request) converted.push_back(each >= 97 ? each - 32 : each);
    return string(converted.begin(), converted.end());
}

bool cacheLookUp(list<string> &cache, string query) {
    auto iteratorOfQuery = find(cache.begin(), cache.end(), query);
    
    if(iteratorOfQuery != cache.end()) {
        string value = *iteratorOfQuery;
        cache.remove(value);
        cache.push_back(value);
        return true;
    } else {
        cache.pop_front();
        cache.push_back(query);
        return false;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    list<string> cache;
    for(int i = 0; i < cacheSize; i++) cache.push_back("");
    for(string city : cities) answer += cacheLookUp(cache, toBiggerCase(city)) ? 1 : 5;
    
    return answer;
}
