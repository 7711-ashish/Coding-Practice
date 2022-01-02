#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    void findTopoSort(int node, vector<int> &visited, vector<int> &topo, vector<vector<int>> &adjList){
        visited[node] = 1;
        for(int i = 0; i < adjList[node].size(); i++){
            if(visited[adjList[node][i]] == 0){
                findTopoSort(adjList[node][i], visited, topo, adjList);
            }
        }
        topo.push_back(node);
    }
    public:
        vector<int> topologicalSort(vector<vector<int>> &adjList){
            vector<int> topo;
            vector<int> visited(adjList.size(), 0);
            for(int i = 0; i < adjList.size(); i++){
                if(visited[i] == 0){
                    findTopoSort(i, visited, topo, adjList);
                }
            }
            reverse(topo.begin(), topo.end());
            return topo;
        }
}

int main(){
    Solution s;
    vector<vector<int>> adjList({0,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0});
    vector<int> topo = s.topologicalSort(adjList);
    for(int i = 0; i < topo.size(); i++){
        cout << topo[i] << " ";
    }
}