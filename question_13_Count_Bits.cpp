// Question # 13 => Leetcode problem # 338. Counting Bits

/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
*/

// solution

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1; 
            
        return ret;
    }
};

int main() {

    Solution obj;   

    int num = 5;

    vector<int> result = obj.countBits(num);

    cout << "Count of set bits from 0 to " << num << ": ";
    for(int val : result){
        cout << val << " ";
    }

    return 0;
}

//output => [0,1,1]