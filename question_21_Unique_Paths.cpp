// question # 21 => leetcode prob(62. Unique Paths)
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

// sol
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[100][100];
        int i, j;

        if(!m || !n){
            return 0;
        }

        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(i==0 || j==0){
                    path[i][j] = 1;
                } else{
                    path[i][j] = path[i][j-1] + path[i-1][j]; 
                }
            }
        }
         return path[m - 1][n - 1];   
    }  
};

// output => 28