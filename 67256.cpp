#include <string>
#include <vector>

using namespace std;

struct position{
    int row = 0;
    int col = 0;
    
    position(int number) {
        switch(number) {
            case 0:
                row = 3;
                col = 1;
                break;
            case -1:
                row = 3;
                col = 0;
                break;
            case -2:
                row = 3;
                col = 2;
                break;
            default:
                row = int((number - 1) / 3);
                col = (number - 1) % 3;
                break;
        }
    }
};


int distanceBetweenTwoPosition(position& a, position& b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

string solution(vector<int> numbers, string hand) {
    position left = position(-1);
    position right = position(-2);
    
    string answer = "";
    
    for(auto number : numbers) {
        position target = position(number);
        if(number == 1 || number == 4 || number == 7) {
            left = target;
            answer += 'L';
        } else if(number == 3 || number == 6 || number == 9) {
            right = target;
            answer += 'R';
        } else {
            int distanceFromLeft = distanceBetweenTwoPosition(left, target);
            int distanceFromRight = distanceBetweenTwoPosition(right, target);
            
            if(distanceFromLeft < distanceFromRight || ((distanceFromLeft == distanceFromRight) && hand == "left")) {
                left = target;
                answer += 'L';
            } else if(distanceFromLeft > distanceFromRight || ((distanceFromLeft == distanceFromRight) && hand == "right")) {
                right = target;
                answer += 'R';
            }
        }
    }
    
    return answer;
}
