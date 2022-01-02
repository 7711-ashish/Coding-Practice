#include &lt;iostream&gt;
#include &lt;cstring&gt;
using namespace std;
  
#define INF 9999
// graph contains 5 vertices
#define V 5 
// an array G that stores adjacency matrix for input graph
 int G[V][V] = {    
    {0, 3, 0, 3, 0},
    {3, 0, 0, 0, 4},
    {0, 0, 0, 2, 1},
    {3, 3, 2, 0, 0},
    {0, 4, 1, 0, 0}};
 
int main () {

    int num_edge;            // number of edge
  
  // mst_vertex - array to track vertices selected for spanning tree
    int mst_vertex[V];
   
 // set selected false initially
    memset (mst_vertex, false, sizeof (mst_vertex));
  
 // set number of edge to 0
    num_edge = 0;
  
   //let 0th vertex be the first to be selected
    mst_vertex[0] = true;
    int x;            //  row 
    int y;            //  col 
  
   // print details of MST
    cout<<"The Minimum Spanning Tree as per Prim's Algorithm:"<<endl;
    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (num_edge &lt; V - 1) {
  
   //Prim's algorithm code
        int min = INF;
        x = 0;
        y = 0;
  
        for (int i = 0; i &lt; V; i++) {
            if (mst_vertex[i]) {
                for (int j = 0; j &lt; V; j++) {
                    if (!mst_vertex[j]&&G[i][j]) { // not in mst_vertex and there is an edge
                        if (min > G[i][j]) { 
                                min = G[i][j];
                                x = i;
                                y = j;
                        }
                    }
                }
            }
        }
        cout << x <<  " - " << y << " :  " << G[x][y];
        cout << endl;
        mst_vertex[y] = true;
        num_edge++;
    }
  
    return 0;
}