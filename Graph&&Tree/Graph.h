#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph{
    public:
        void printGraph(vector<vector<int>>);
        void insertEdge(vector<vector<int>>, int, int);
        void initializeGraph();
};


// common methods

void printGraph(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// Methods for labeled graph

void insertEdge(vector<vector<int>> &v, int i, int j, bool directed){
    v[i][j] = 1;
    if(directed){
        v[j][i] = 1;
    }
}

void initializeGraph(int N, vector<vector<int>> &edges, bool directed){
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j] = 0;
        }
    }

    for(int i = 0;i<edges.size(); i++){
        insertEdge(v, edges[i][0], edges[i][1], directed);
    }

    printGraph(v);
}

//Methods for weighted graph

void insertEdgeWeighted(vector<vector<int>> &v, int i, int j, int vertexValue, bool directed){
    v[i][j] = vertexValue;
    if(directed){
        v[j][i] = vertexValue;
    }
}

void intializeGraphWeighted(int N, vector<vector<int>> &edges, bool direceted){
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){     
            v[i][j] = 0;
        }
    }

    for(int i = 0;i<edges.size(); i++){
        insertEdgeWeighted(v, edges[i][0], edges[i][1], edges[i][2], direceted);
    }

    printGraph(v);
}

void dfs(vector<vector<int>> &v, int i, int j){ 
    queue<int> q;

}