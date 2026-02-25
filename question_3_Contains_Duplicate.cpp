// Question # 03  -> Leetcode 217 (Contains Duplicate)

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


Example 1:
Input: nums = [1,2,3,1]
Output: tru
Explanation:
The element 1 occurs at the indices 0 and 3.
*/


// Solurion
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // native approach => nested for loop => time: 0(n^2)
        // optimal approach => set => time: 0(n), space: 0(n)

        unordered_set<int> set;

        for(int num:nums){
            if(set.find(num) != set.end()){
                return true;
            }
            set.insert(num);
        }
        return false;
        
    }
};

int main(){
  Solution obj;
  vector<int> nums = {1,2,3,1};
  bool result = obj.containsDuplicate(nums);

  if (obj.containsDuplicate(nums))
  {
    cout << "Duplicate Found" << endl;
  } else{
    cout << "Duplicate Not Found" << endl;
  }
  

  return 0;
}

// Output (true)
// Duplicate Found