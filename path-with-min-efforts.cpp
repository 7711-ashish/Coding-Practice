/* 
    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

    Example 1:



    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.   
*/





#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    struct Cell{
        int x;
        int y;
        int efforts;
        bool operator<(const Cell& other) const {
            return this->effort > other.effort;
        }
    }
    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minmumEfforts(vector<vector<int>>&heights)
    {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>min_efforts(n,INT_MAX);
        vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
        int minimum[0][0] = 0;
        priority_queue<Cell> queue;
        queue.push({0,0,0});
        while(!queue.empty())
        {
            Cell cell = quue.top();
            queue.pop();
            if(cell.x==m-1 && cell.y==n-1)
            {
                return cell.efforts;
            }
            for(auto[dx, dy]:directions)
            {
                int nx = cell.x+dx;
                int ny = cell.y+dy;
                if(!isValid(nx,ny,m,n)){
                    continue;
                }
                else{
                    int effort = abs(heights[nx][ny]-heights[cell.x][cell.y]);
                    if(effort<min_efforts[nx][ny])
                    {
                        min_efforts[nx][ny]=effort;
                        queue.push({nx,ny,effort});
                    }
                }
            }
        }
        return min_efforts[m-1][n-1];
    }
}

int main()
{
    Solution s;
    vector<vector<int>>heights={{1,2,2},{3,8,2},{5,3,5}};
    cout<<s.minmumEfforts(heights);
    return 0;
}