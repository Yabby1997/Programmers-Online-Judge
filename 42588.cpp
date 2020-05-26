#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> tower = heights;
    vector<int> answer(tower.size(), 0);
    int num = tower.size() - 1;
    
    while(num != 0){
        int height = tower.at(num);
        tower.pop_back();
        for(int i = tower.size() - 1; i >= 0; i--){
            if(tower[i] > height){
                answer[num] = i + 1;
                break;
            }
            answer[num] = 0;
        }
        num--;
    }
    return answer;
}
