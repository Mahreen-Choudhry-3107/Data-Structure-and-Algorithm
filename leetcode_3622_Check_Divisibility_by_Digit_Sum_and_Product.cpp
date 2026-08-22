class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;

        while (temp > 0) {
            int currentDigit = temp % 10;
            digitSum += currentDigit;
            digitProduct *= currentDigit;
            temp /= 10;
        }
        int totalDivisor = digitSum + digitProduct;
        return (n % totalDivisor == 0);
    }
};
