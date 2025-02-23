#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include "Graph&&Tree/Graph.h"
#include "Graph&&Tree/Tree.h"

using namespace std;

int main(){
    // int numberOfNodes = 5;
    // bool directed = false;
    // vector<vector<int>> edges = {{0,1}, {0,2}, {0,4}, {1,3}, {3,4}, {2,4}};
    // initializeGraph(numberOfNodes, edges, directed);
    
    vector<int> nodes = {6, 1, 2, 0, 4, 5, 8};
    TreeNode* root = initializeBST(nodes);
    BFS(root);
} 