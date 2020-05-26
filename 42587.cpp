#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<vector<int>> document;
    
    for(int i = 0; i < priorities.size(); i++){
        vector<int> temp{i, priorities[i]};
        document.push_back(temp);
    }
    
    sort(priorities.begin(), priorities.end());
	
	int currentBest = priorities.back();
    vector<int> doc = document.front();
    while(1){
		if(currentBest == doc[1]){
            if(doc[0] == location){
				answer++;
                break;
            }
            document.pop_front();
            doc = document.front();
            priorities.pop_back();
            currentBest = priorities.back();
            answer++;
        }
		else{
        	document.pop_front();
        	document.push_back(doc);
        	doc = document.front();
		}
    }    
    return answer;
}

int main(){
	vector<int> test{1, 1, 9, 1, 1, 1};
	int loc = 0;
	cout<<solution(test, loc)<<endl;
	return 0;
}


