// Question # 23 (207. Course Schedule)
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
*/

// Solution
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& nums) {
        vector<vector<int>> adj(v);
        for(int i=0;i<nums.size();i++)
            adj[nums[i][1]].push_back(nums[i][0]);
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
                indegree[it]+=1;
        }
        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]-=1;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(topo.size()==v)
            return true;
        return false;
    }
};

//output => true