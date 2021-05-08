using namespace std;

int solution(vector<int> stones, int k) {
    int max = *max_element(stones.begin(), stones.end());
    int min = *min_element(stones.begin(), stones.end());
    int pivot = (max + min) / 2;
    
    while(true) {
        int bestLength = 0;
        int currentLength = 0;
        pivot = (max + min) / 2;
        
        if(min > max) {
            return pivot + 1;
        }
        
        for(int i = 0; i < stones.size(); i++) {
            if(stones[i] - pivot > 0)
                currentLength = 0;
            else {
                currentLength++;
                if(currentLength > bestLength)
                    bestLength = currentLength;
            }
        }
        
        if(bestLength < k) {
            min = pivot + 1;
        } else {
            max = pivot - 1;
        }
    }
}
