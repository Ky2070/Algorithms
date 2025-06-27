#include<iostream>
#include "LongestPalindromic.h"
#include<string>

std::string Solution4::longestPalindrome(std::string s) {
	if (s.empty()) return "";

	int start = 0, maxLen = 1;
	int n = s.length();

	//Hàm mở rộng từ tâm ra hai bên để kiểm tra đối xứng
	auto expandAroundCenter = [&](int left, int right) {
		while (left >= 0 && right < n && s[left] == s[right]) {
			if (right - left + 1 > maxLen) {
				start = left;
				maxLen = right - left + 1;
			}
			left--;
			right++;
		}
	};

	//Thử mọi tâm có thể
	for (int i = 0; i < n; i++) {
		expandAroundCenter(i, i); //Tâm lẻ
		expandAroundCenter(i, i + 1); //Tâm chẵn
	}

	return s.substr(start, maxLen);
}
