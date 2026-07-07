/*
3754. Concatenate Non-Zero Digits and Multiply by Sum I

solution
*******************************`*******************************

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x = 0, sum = 0;

        for (char c : s) {
            if (c != '0') {
                int digit = c - '0';
                x = x * 10 + digit;
                sum += digit;
            }
        }

        return x * sum;
    }
};
*/