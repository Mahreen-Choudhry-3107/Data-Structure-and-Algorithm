// Question # 12 => Leetcode # 191. Number of 1 Bits
/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.
*/

//solution
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n > 0){
            if(n & 1 == 1){
                ans++;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main() {

    Solution obj;   

    uint32_t n = 11;   

    int result = obj.hammingWeight(n);

    cout << "Number of 1 bits: " << result;

    return 0;
}

//output => 3