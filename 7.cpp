/*
Island Perimeter

Solution
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

*/

class Solution {
public:
    int perimeter(vector<vector<int>>& grid,int i,int j,int row,int col)
    {
        int p=0;
        if(i-1<0)
            p++;
        else if(grid[i-1][j]==0)
            p++;
        if(i+1>=row)
            p++;
        else if(grid[i+1][j]==0)
            p++;
        if(j-1<0)
            p++;
        else if(grid[i][j-1]==0)
            p++;
        if(j+1>=col)
            p++;
        else if(grid[i][j+1]==0)
            p++;
        
        return p;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int pm = 0;
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                   pm+=perimeter(grid,i,j,row,col);
                }
            }
        }
        return pm;
    }
};
