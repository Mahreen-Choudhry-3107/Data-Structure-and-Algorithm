/*
3518. Smallest Palindromic Rearrangement II

Solution:
*****************************************************************

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        if (!isPalindromePossible(count))
            return "";

        vector<int> halfCount(26, 0);
        char midLetter = '\0';
        getHalfCountAndMidLetter(count, halfCount, midLetter);

        int totalPerm = calculateTotalPermutations(halfCount);
        if (k > totalPerm)
            return "";

        vector<char> leftHalf = generateLeftHalf(halfCount, k);

        string left(leftHalf.begin(), leftHalf.end());
        string right = left;
        reverse(right.begin(), right.end());

        if (midLetter != '\0')
            return left + string(1, midLetter) + right;
        else
            return left + right;
    }

private:
    bool isPalindromePossible(vector<int>& count) {
        int oddCount = 0;
        for (int freq : count) {
            if (freq % 2)
                oddCount++;
        }
        return oddCount <= 1;
    }

    void getHalfCountAndMidLetter(vector<int>& count,
                                  vector<int>& halfCount,
                                  char &midLetter) {
        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2)
                midLetter = char(i + 'a');
        }
    }

    int calculateTotalPermutations(vector<int>& halfCount) {
        return countArrangements(halfCount);
    }

    vector<char> generateLeftHalf(vector<int>& halfCount, int k) {
        int halfLen = accumulate(halfCount.begin(), halfCount.end(), 0);
        vector<char> left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0)
                    continue;

                halfCount[i]--;

                int arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    left.push_back(char(i + 'a'));
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        return left;
    }

    int countArrangements(vector<int>& count) {
        int total = accumulate(count.begin(), count.end(), 0);
        long long res = 1;

        for (int freq : count) {
            res *= nCk(total, freq);

            if (res >= MAX)
                return MAX;

            total -= freq;
        }

        return (int)res;
    }

    int nCk(int n, int k) {
        long long res = 1;
        k = min(k, n - k);

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }
        return (int)res;
    }
};
*/