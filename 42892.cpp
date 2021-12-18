#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int number, x, y;
    Node *leftChild, *rightChild;
};

bool compareNodes(Node left, Node right) {
    return (left.y > right.y || (left.y == right.y && left.x < right.x));
}

void addChild(Node *current, Node *parent) {
    if(parent == NULL) { return; }
    
    if(current->x < parent->x) {
        if(parent->leftChild == NULL) { parent->leftChild = current; }
        else { addChild(current, parent->leftChild); }
    } else {
        if(parent->rightChild == NULL) { parent->rightChild = current; }
        else { addChild(current, parent->rightChild); }
    }
}

void preorderTraverse(vector<int>* result, Node* current) {
    if(current == NULL) { return; }
    result->push_back(current->number);
    preorderTraverse(result, current->leftChild);
    preorderTraverse(result, current->rightChild);
}

void postorderTraverse(vector<int>* result, Node* current) {
    if(current == NULL) { return; }
    postorderTraverse(result, current->leftChild);
    postorderTraverse(result, current->rightChild);
    result->push_back(current->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<int> preorderTraversalResult;
    vector<int> postorderTraversalResult;
    vector<Node> nodes;
    Node *root;
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        Node node;
        node.number = i + 1;
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.leftChild = NULL;
        node.rightChild = NULL;
        nodes.push_back(node);
    }
    
    sort(nodes.begin(), nodes.end(), compareNodes);
    root = &nodes[0];
    
    for(int i = 1; i < nodes.size(); i++) { addChild(&nodes[i], root); }
    preorderTraverse(&preorderTraversalResult, root);
    postorderTraverse(&postorderTraversalResult, root);
    
    return vector<vector<int>>{preorderTraversalResult, postorderTraversalResult};
}
