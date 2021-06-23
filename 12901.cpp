#include <string>
#include <vector>

using namespace std;

vector<int> daysToEachMonth = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

string solution(int a, int b) {
    switch((daysToEachMonth[a - 1] + b) % 7) {
        case 1:
            return "FRI";
        case 2 :
            return "SAT";
        case 3 :
            return "SUN";
        case 4 : 
            return "MON";
        case 5:
            return "TUE";
        case 6:
            return "WED";
        case 0:
            return "THU";
    }
}
