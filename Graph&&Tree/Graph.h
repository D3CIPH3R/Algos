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

vector<vector<int>> initializeGraph(int N, vector<vector<int>> &edges, bool directed){
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j] = 0;
        }
    }

    for(int i = 0;i<edges.size(); i++){
        insertEdge(v, edges[i][0], edges[i][1], directed);
    }
    return v;
}

//Methods for weighted graph

void insertEdgeWeighted(vector<vector<int>> &v, int i, int j, int vertexValue, bool directed){
    v[i][j] = vertexValue;
    if(directed){
        v[j][i] = vertexValue;
    }
}

vector<vector<int>> initializeGraphWeighted(int N, vector<vector<int>> &edges, bool direceted){
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){     
            v[i][j] = 0;
        }
    }

    for(int i = 0;i<edges.size(); i++){
        insertEdgeWeighted(v, edges[i][0], edges[i][1], edges[i][2], direceted);
    }
    return v;
}

void BFS(vector<vector<int>> &v, int start){ 
    queue<int> q;
    int n = v.size();
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i=0;i<n;i++){
            if(v[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }  
    }
}

void DFS(vector<vector<int>> &v, vector<bool> &visited, int node){
    visited[node] = true;
    cout << node << " ";

    for(int i=0;i<v.size();i++){
        if(v[node][i] == 1 && !visited[i]){
            DFS(v, visited, i);
        }
    }
}