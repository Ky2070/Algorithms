#include <unordered_map>
#include "TwoSum.h"


std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            return { map[complement], i };
        }

        map[nums[i]] = i;
    }

    return {};
}
