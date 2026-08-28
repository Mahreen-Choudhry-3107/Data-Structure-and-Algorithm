class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int odd_count = 0, odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }
        if (odd_count > 1) return "";

        int half = n / 2;
        vector<int> half_count = count;
        if (n % 2 != 0) half_count[odd_char]--;
        for (int i = 0; i < 26; ++i) half_count[i] /= 2;

        string best = "";

        for (int pos = half; pos >= -1; --pos) {
            vector<int> avail = half_count;
            bool ok = true;
            int match_len = (pos == half) ? half : pos;
            for (int i = 0; i < match_len; ++i) {
                int c = target[i] - 'a';
                if (avail[c] == 0) { ok = false; break; }
                avail[c]--;
            }
            if (!ok) continue;

            string half_str(half, ' ');
            for (int i = 0; i < match_len; ++i) half_str[i] = target[i];

            if (pos >= 0 && pos < half) {
                int need = target[pos] - 'a' + 1;
                int chosen = -1;
                for (int c = need; c < 26; ++c) {
                    if (avail[c] > 0) { chosen = c; break; }
                }
                if (chosen == -1) continue;
                avail[chosen]--;
                half_str[pos] = (char)('a' + chosen);
            }

            int fill_start = (pos == half) ? half : (pos >= 0 ? pos + 1 : 0);
            bool fill_ok = true;
            for (int i = fill_start; i < half; ++i) {
                int c = 0;
                while (c < 26 && avail[c] == 0) c++;
                if (c == 26) { fill_ok = false; break; }
                half_str[i] = (char)('a' + c);
                avail[c]--;
            }
            if (!fill_ok) continue;

            string result(n, ' ');
            for (int i = 0; i < half; ++i) {
                result[i] = half_str[i];
                result[n - 1 - i] = half_str[i];
            }
            if (n % 2 != 0) result[half] = (char)('a' + odd_char);

            if (result > target) {
                best = result;
                break;
            }
        }

        return best;
    }
};
