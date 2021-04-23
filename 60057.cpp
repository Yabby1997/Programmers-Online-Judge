#include <string>
#include <vector>

using namespace std;

int solution(string s) {    
    int minimum = s.size();
    
    for(int length = 1; length <= s.size() / 2; length++) {
        vector<string> temp;

        int from = 0;
        while(from + length <= s.size()) {
            temp.push_back(s.substr(from, length));
            from += length;
        }
        
        int shortenLength = s.size();
        string lastString = temp[0];
        int count = 1;
        
        for(int i = 1; i < temp.size(); i++) {
            if(temp[i] == lastString) {
                count += 1;
            } else {
                if(count >= 1) {
                    int candidate = shortenLength - (count * length) + to_string(count).size() + length;
                    shortenLength = shortenLength > candidate ? candidate : shortenLength;
                }
                lastString = temp[i];
                count = 1;
            }
        }
        if(count >= 1) {
            int candidate = shortenLength - (count * length) + to_string(count).size() + length;
            shortenLength = shortenLength > candidate ? candidate : shortenLength;
        }
        minimum = minimum > shortenLength ? shortenLength : minimum;
    }
    
    return minimum;
}
