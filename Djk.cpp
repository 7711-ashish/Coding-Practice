#include<bits/stdc++.h>
using namespace std;
bool visited[6];
int dist[6];
void dijkstra(int graph[6][6],int index){
 for(int i=0;i<6;i++){
    dist[i]=INT_MAX;
    visited[i]=false;
 }
 queue<int> q;
 q.push(index);
 dist[index]=0;
 while(!q.empty()){
    int r=q.front();
    q.pop();
    visited[r]=true;
    for(int i=0;i<6;i++){
        if(graph[i][r]!=0){
            if(visited[i])continue;
                if(dist[i]>dist[r]+graph[i][r])
                    dist[i]=dist[r]+graph[i][r];
                    q.push(i);
        }
    }
 }
 cout<<"Node \t distance\n";
 for(int i=0;i<6;i++){
    cout<<(char)(i+'A')<<"\t"<<dist[i]<<"\n";
 }
}
int main(){
 int graph[6][6]={
 {0,1,2,0,0,0},
 {1,0,1,3,2,0},
 {2,1,0,1,2,0},
 {0,3,1,0,4,3},
 {0,2,2,4,0,3},
 {0,0,0,3,3,0}
 };
 
    cout<<"For Node A the Shortest paths are as follows:-\n";
    dijkstra(graph,0);
    return 0;
}
