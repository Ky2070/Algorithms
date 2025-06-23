#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (map.find(complement) != map.end()) {
                return { map[complement], i };
            }

            map[nums[i]] = i;
        }

        return {}; // không xảy ra theo đề bài
    }
};

int main() {
    vector<int> nums = {11, 4, 7, 5};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices found: ";
    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}
