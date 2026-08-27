#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }
        
        int matched = 0;
        while (matched < n) {
            int c = target[matched] - 'a';
            if (count[c] == 0) {
                break;
            }
            count[c]--;
            matched++;
        }
        
        for (int pos = std::min(matched, n - 1); pos >= 0; pos--) {
            if (pos < matched) {
                count[target[pos] - 'a']++;
            }
            int targetChar = target[pos] - 'a';
            for (int c = targetChar + 1; c < 26; c++) {
                if (count[c] > 0) {
                    std::string res = target.substr(0, pos);
                    res += (char)('a' + c);
                    count[c]--;
                    
                    for (int i = 0; i < 26; i++) {
                        while (count[i] > 0) {
                            res += (char)('a' + i);
                            count[i]--;
                        }
                    }
                    return res;
                }
            }
        }
        
        return "";
    }
};
