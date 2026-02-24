#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;

        for(int i = 0; i < arr.size(); i++){
            int first = arr[i];
            int second = tar - first;

            if(m.find(second) != m.end()){
                return {m[second], i};
            }

            m[first] = i;
        }

        return {};
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> result = s.twoSum(arr, target);

    for(int x : result)
        cout << x << " ";

    return 0;
}