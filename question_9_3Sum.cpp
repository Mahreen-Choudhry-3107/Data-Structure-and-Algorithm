#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        if (arr.size() < 3) return {};

        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for (int idx = 0; idx < arr.size() - 2; idx++) {
            if (idx > 0 && arr[idx] == arr[idx - 1]) continue;

            int start = idx + 1;
            int end = arr.size() - 1;

            while (start < end) {
                int total = arr[idx] + arr[start] + arr[end];

                if (total == 0) {
                    ans.push_back({arr[idx], arr[start], arr[end]});

                    while (start < end && arr[start] == arr[start + 1]) start++;
                    while (start < end && arr[end] == arr[end - 1]) end--;

                    start++;
                    end--;
                } 
                else if (total < 0) start++;
                else end--;
            }
        }
        return ans;
    }
};

//Output => [[-1,-1,2],[-1,0,1]]