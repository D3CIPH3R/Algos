#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph{
    public:
        void insertEdge(vector<vector<int>>, int, int);
        void printGraph(vector<vector<int>>);
        void initializeGraph();
};

void insertEdge(vector<vector<int>> &v, int i, int j){
    v[i][j] = 1;
    v[j][i] = 1;
}

void printGraph(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void initializeGraph(){
    int N = 5;
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j] = 0;
        }
    }

    insertEdge(v, 0, 1);
    insertEdge(v, 0, 2);
    insertEdge(v, 0, 3);
    insertEdge(v, 0, 4);
    insertEdge(v, 1, 3);
    insertEdge(v, 2, 4);
    insertEdge(v, 3, 4);

    printGraph(v);
}