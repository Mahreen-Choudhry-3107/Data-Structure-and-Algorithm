// Question # 11 => Leetcode  # 371. Sum of Two Integers
/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
*/


//Solution
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int x = a ^ b;
            int y = (a & b) << 1;
            a = x; b = y;
        }
        return a;
    }
};

int main() {

    Solution obj;   

    int a = 5;
    int b = 7;

    int result = obj.getSum(a, b);

    cout << "Sum is: " << result;

    return 0;
}

//Output => 3