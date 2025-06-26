#include<iostream>
#include "MedianSortedArrays.h"
#include<vector>
#include<algorithm>

double Solution3::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		std::vector<int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
	}
	int left = 0;
	int m = nums1.size();
	int n = nums2.size();
	int right = m;

	while (left <= right) {
		int i = (left + right) / 2;
		int j = (m + n + 1) / 2 - i;

		int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
		int minRight1 = (i == m) ? INT_MAX : nums1[i];

		int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
		int minRight2 = (j == n) ? INT_MAX : nums2[j];

		if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
			if ((m + n) % 2 == 0) {
				return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
			}
			else {
				return std::max(maxLeft1, maxLeft2);
			}
		}
		else if (maxLeft1 > minRight2) {
			right = i - 1;
		}
		else {
			left = i + 1;
		}
	}
	return 0.0;
}