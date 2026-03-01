// Question # 14 => Leetcode => 190. Reverse Bits
/*
Reverse bits of a given 32 bits signed integer.
Example 1:

Input: n = 43261596

Output: 964176192
*/


//solution
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        int d = 0;
        while(n > 0){
            x += (n % 2) << (31 - d);
            n >>= 1;
            d++;
        }
        return x;
    }
};

int main() {

    Solution obj;   
    uint32_t n = 43261596; 

    uint32_t result = obj.reverseBits(n);

    cout << "Reversed Bits Result: " << result;

    return 0;
}

//output => 964176192