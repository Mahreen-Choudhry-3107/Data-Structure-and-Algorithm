/*

class Solution {
public:

    unordered_map<int, int> kFactorCounts[10] = {
        {},                 // 0
        {},                 // 1
        {{2, 1}},           // 2
        {{3, 1}},           // 3
        {{2, 2}},           // 4
        {{5, 1}},           // 5
        {{2, 1}, {3, 1}},   // 6
        {{7, 1}},           // 7
        {{2, 3}},           // 8
        {{3, 2}}            // 9
    };

    unordered_map<int, int> getPrimeCount(long long t, bool &isDivisible) {
        unordered_map<int, int> count = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        vector<int> primes = {2, 3, 5, 7};

        for (int prime : primes) {
            while (t % prime == 0) {
                t /= prime;
                count[prime]++;
            }
        }

        isDivisible = (t == 1);
        return count;
    }

    unordered_map<int, int> getPrimeCountFromString(string num) {
        unordered_map<int, int> count = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        for (char c : num) {
            int d = c - '0';

            for (auto &[prime, freq] : kFactorCounts[d]) {
                count[prime] += freq;
            }
        }

        return count;
    }

    unordered_map<int, int> getFactorCount(
        unordered_map<int, int> count
    ) {
        unordered_map<int, int> res;

        int count8 = count[2] / 3;
        int remaining2 = count[2] % 3;

        int count9 = count[3] / 2;
        int count3 = count[3] % 2;

        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;

        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }

        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count6 = 1;
            count3 = 0;
            count4 = 0;
        }

        res[2] = count2;
        res[3] = count3;
        res[4] = count4;
        res[5] = count[5];
        res[6] = count6;
        res[7] = count[7];
        res[8] = count8;
        res[9] = count9;

        return res;
    }

    string construct(unordered_map<int, int> factors) {
        string res;

        for (int digit = 2; digit < 10; digit++) {
            res += string(factors[digit], char('0' + digit));
        }

        return res;
    }

    bool isSubset(
        unordered_map<int, int> a,
        unordered_map<int, int> b
    ) {
        for (auto &[key, value] : a) {
            if (b[key] < value)
                return false;
        }

        return true;
    }

    unordered_map<int, int> subtract(
        unordered_map<int, int> a,
        unordered_map<int, int> b
    ) {
        unordered_map<int, int> res = a;

        for (auto &[key, value] : b) {
            res[key] = max(0, res[key] - value);
        }

        return res;
    }

    int sumValues(unordered_map<int, int> count) {
        int sum = 0;

        for (auto &[key, value] : count) {
            sum += value;
        }

        return sum;
    }

    string smallestNumber(string num, long long t) {

        bool isDivisible;

        unordered_map<int, int> primeCount =
            getPrimeCount(t, isDivisible);

        if (!isDivisible)
            return "-1";

        unordered_map<int, int> factorCount =
            getFactorCount(primeCount);

        if (sumValues(factorCount) > num.length()) {
            return construct(factorCount);
        }

        unordered_map<int, int> primeCountPrefix =
            getPrimeCountFromString(num);

        size_t firstZeroIndex = num.find('0');

        if (firstZeroIndex == string::npos) {

            firstZeroIndex = num.length();

            if (isSubset(primeCount, primeCountPrefix)) {
                return num;
            }
        }

        for (int i = num.length() - 1; i >= 0; i--) {

            int d = num[i] - '0';

            primeCountPrefix =
                subtract(
                    primeCountPrefix,
                    kFactorCounts[d]
                );

            int spaceAfterThisDigit =
                num.length() - 1 - i;

            if (i > firstZeroIndex)
                continue;

            for (int biggerDigit = d + 1;
                 biggerDigit < 10;
                 biggerDigit++) {

                auto remaining =
                    subtract(
                        primeCount,
                        primeCountPrefix
                    );

                auto factorsAfterReplacement =
                    getFactorCount(
                        subtract(
                            remaining,
                            kFactorCounts[biggerDigit]
                        )
                    );

                if (sumValues(factorsAfterReplacement)
                    <= spaceAfterThisDigit) {

                    int fillOnes =
                        spaceAfterThisDigit -
                        sumValues(factorsAfterReplacement);

                    return num.substr(0, i)
                        + char('0' + biggerDigit)
                        + string(fillOnes, '1')
                        + construct(factorsAfterReplacement);
                }
            }
        }

        unordered_map<int, int> factorsAfterExtension =
            getFactorCount(primeCount);

        int ones =
            num.length() + 1 -
            sumValues(factorsAfterExtension);

        return string(ones, '1')
            + construct(factorsAfterExtension);
    }
};

*/