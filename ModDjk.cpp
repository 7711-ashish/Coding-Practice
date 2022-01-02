#include<bits/stdc++.h>
using namespace std;
bool visited[6];
int dist[6];
void dijkstra(int graph[6][6],int index,int tr){
    int prev[6];
    for(int i=0;i<6;i++){
        dist[i]=INT_MAX;
        prev[i]=-1;
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
 if(dist[i]>dist[r]+graph[i][r]){
 dist[i]=dist[r]+graph[i][r];
 prev[i]=r;
 }
 q.push(i);
 }
 }
 }
 vector<char>path;
 if(dist[tr]==INT_MAX)return;
 cout<<"Shortest Path to "<<(char)(tr+'A')<<" :-\n";
 for(int i=tr;i!=index;i=prev[i]){
 path.push_back((char)(i+'A'));
 }
 reverse(path.begin(),path.end());
 for(auto it:path){
 cout<<it<<" ";
 }
 cout<<"\n";
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
 
 for(int i=1;i<6;i++){
 dijkstra(graph,0,i);
 }
 return 0;
}
