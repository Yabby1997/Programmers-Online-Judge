#include<stdio.h>
#include<vector>

using namespace std;

int keyWidth, lockWidth, width;
vector<vector<int>> keyMatrix, lockMatrix, board, copyOfBoard;
vector<vector<int>> rotatedKey;

bool solution(vector<vector<int>> key, vector<vector<int>> lock);
void buildBoard();
void rotateKey();
bool isUnlocked();

int main() {
    printf("%d\n", solution(vector<vector<int>>{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, vector<vector<int>>{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}));
    return 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keyMatrix = key;
    lockMatrix = lock;
    
    keyWidth = int(key.size());
    lockWidth = int(lock.size());
    width = lockWidth + 2 * (keyWidth - 1);
    
    rotatedKey = keyMatrix;
    rotateKey();
    rotateKey();
    rotateKey();
    
    buildBoard();
    
    for(int i = 0; i < lockWidth + keyWidth - 1; i++) {
        for(int j = 0; j < lockWidth + keyWidth - 1; j++) {
            
            for(int k = 0; k < 4; k++) {
                copyOfBoard = board;
                for(int l = 0; l < keyWidth; l++) {
                    for(int m = 0; m < keyWidth; m++) {
                        copyOfBoard[i + l][j + m] += rotatedKey[l][m];
                    }
                }
                rotateKey();
                
                if(isUnlocked()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void rotateKey() {
    vector<vector<int>> targetKey = vector<vector<int>>(keyWidth, vector<int>(keyWidth, 0));
    
    for(int i = 0; i < keyWidth; i++) {
        vector<int> row = rotatedKey[i];
        for(int j = 0; j < keyWidth; j++) {
            targetKey[j][keyWidth - 1 - i] = row[j];
        }
    }
    
    rotatedKey = targetKey;
}

void buildBoard() {
    board = vector<vector<int>>(width, vector<int>(width, 0));
    
    for(int i = (keyWidth - 1); i < keyWidth - 1 + lockWidth; i++) {
        for(int j = (keyWidth - 1); j < keyWidth - 1 + lockWidth; j ++) {
            board[i][j] = lockMatrix[i + 1 - keyWidth][j + 1 - keyWidth];
        }
    }
}

bool isUnlocked() {
    int from = keyWidth - 1;
    int to = keyWidth + lockWidth - 1;
    for(int i = from; i < to; i++) {
        for(int j = from; j < to; j ++) {
            if(copyOfBoard[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

