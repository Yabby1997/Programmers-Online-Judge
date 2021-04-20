#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adjacencyMatrix;
vector<int> vertices;
vector<int> stack;
int networks = 0;

void DFS(int vertex);

int solution(int n, vector<vector<int>> computers) {
    int answer = n;
    
    adjacencyMatrix = computers;
    vertices = vector<int>(n, 500);
    
    for(int i = 0; i < n; i++) {
        if(vertices[i] == 500) {
            networks += 1;
            vertices[i] = networks;
        }
        
        DFS(i);
    }
    
    return networks;
}

void DFS(int vertex) {
    for(int i = 0; i < adjacencyMatrix[vertex].size(); i++) {
        if(adjacencyMatrix[vertex][i] && vertices[i] == 500) {
            vertices[i] = vertices[vertex];
            DFS(i);
        }
    }
}
