#include<iostream>
#include<unordered_set>
#include "LongestSubstring.h"

int Solution2::lengthOfLongestSubstring(std::string s) {
	std::unordered_set<char> seen;
	int left = 0, maxLen = 0;

	for (int right = 0; right < s.length(); right++) {
		while (seen.count(s[right])) {
			seen.erase(s[left]);
			left++;
		}
		seen.insert(s[right]);

		int currentLength = right - left + 1;
		if (currentLength > maxLen) {
			maxLen = currentLength;
		}
	}
	return maxLen;
}