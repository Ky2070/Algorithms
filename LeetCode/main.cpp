#include <iostream>
#include <vector>
#include <cctype>
#include <random>
#include <string>
#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LongestSubstring.h"
#include "MedianSortedArrays.h"
#include "HeapSort.h"
#include "LongestPalindromic.h"
#include "Zigzag.h"
//Tạo hàm thực thi riêng cho từng bài

void static runTwoSum() {
	//Thiết lập bộ tạo số ngẫu nhiên
	std::random_device rd;
	std::mt19937 gen(rd());

	//Thiết lập phạm vi phần tử mảng (ví dụ: 0 đến 20);
	std::uniform_int_distribution<> dist(0, 20);
	//Thiết lập số lượng phần tử mảng (ví dụ từ 5 đến 20 phần tử)
	std::uniform_int_distribution<> size_dist(5, 20);
	int n = size_dist(gen);
	
	//Tạo vector ngẫu nhiên
	std::vector<int> nums;
	for (int i = 0; i < n; i++) {
		nums.push_back(dist(gen));
	}

	//In mảng ra màn hình
	std::cout << "Generated nums: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	//random target
	std::uniform_int_distribution<int> target_dist(0, 20);
	int target = target_dist(gen);
	std::cout << "Random target: " << target << std::endl;

	Solution sol;
	std::vector<int> result = sol.twoSum(nums, target);
	std::cout << "Indices found: ";
	for (int index : result) {
		std::cout << index << " ";
	}

	std::cout << std::endl;
}

void static runAddTwoNumbers() {
	//Random setup
	std::random_device rd;
	std::mt19937 gen(rd());
	
	// Độ dài mảng ngẫu nhiên từ 0 đến 8;
	std::uniform_int_distribution<> size_dist(0, 8);
	int size1 = size_dist(gen);
	int size2 = size_dist(gen);

	// Các chữ số từ 0 đến 9 (vì từng node là 1 chữ số)
	std::uniform_int_distribution<> digit_dist(0, 9);

	std::vector<int> arr1, arr2;
	
	for (int i = 0; i < size1; i++) {
		arr1.push_back(digit_dist(gen));
	}
	for (int i = 0; i < size2; i++) {
		arr2.push_back(digit_dist(gen));
	}

	// In ra hai dãy số
	std::cout << "List 1: ";
	for (int x : arr1) std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "List 2: ";
	for (int x : arr2) std::cout << x << " ";
	std::cout << std::endl;

	ListNode* l1 = createList(arr1.data(), arr1.size());
	ListNode* l2 = createList(arr2.data(), arr2.size());

	Solution1 sol1;
	ListNode* result = sol1.addTwoNumbers(l1, l2);

	std::cout << "Result of addition: ";
	printList(result);
}

// Hàm chạy LongestSubstring
void runLengthOfLongestSubstring() {
	Solution2 sol2;
	std::string test1 = "abcabcbb";
	std::string test2 = "bbbbb";
	std::string test3 = "pwwkew";

	std::cout << "Test 1 (\"abcabcbb\"): " << sol2.lengthOfLongestSubstring(test1) << std::endl;
	std::cout << "Test 2 (\"bbbbb\"): " << sol2.lengthOfLongestSubstring(test2) << std::endl;
	std::cout << "Test 3 (\"pwwkew\"): " << sol2.lengthOfLongestSubstring(test3) << std::endl;
}

void runMedianSortedArrays() {
	//Random setup;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distLen(1, 4);
	std::uniform_int_distribution<> distVal(1, 6);

	int len1 = distLen(gen);
	int len2 = distLen(gen);

	std::vector<int> nums1(len1);
	std::vector<int> nums2(len2);

	for (int& x : nums1) x = distVal(gen);
	for (int& x : nums2) x = distVal(gen);

	// ✅ In ra trước khi sort
	std::cout << "Before sort:\n";
	std::cout << "nums1: ";
	for (int x : nums1) std::cout << x << " ";
	std::cout << "\nnums2: ";
	for (int x : nums2) std::cout << x << " ";
	std::cout << "\n";

	// ✅ Tạo bản sao và sort bản sao
	std::vector<int> sortedNums1 = nums1;
	std::vector<int> sortedNums2 = nums2;

	heapSort(sortedNums1);
	heapSort(sortedNums2);

	// ✅ In sau khi sort
	std::cout << "After sort:\n";
	std::cout << "sortedNums1: ";
	for (int x : sortedNums1) std::cout << x << " ";
	std::cout << "\nsortedNums2: ";
	for (int x : sortedNums2) std::cout << x << " ";
	std::cout << "\n";

	Solution3 sol3;
	std::cout << "Median Sorted Arrays: " << sol3.findMedianSortedArrays(sortedNums1, sortedNums2) << std::endl;
}

void runLongestPalindromic() {
	std::string s = "babad";
	Solution4 sol4;
	std::cout << "Chuỗi đối xứng dài nhất: " << sol4.longestPalindrome(s) << std::endl;
	std::string s1 = "abbd";
	std::cout << "Chuỗi đối xứng dài nhất của s1: " << sol4.longestPalindrome(s1) << std::endl;
}

void runZigzagConversion() {
	std::string s = "PAYPALISHING";
	Solution5 sol5;
	std::cout << "Zigzag-Conversion: " << sol5.zigzagConvert(s) << std::endl;
}
int main() {
	while (true) {
		int choice;
		std::cout << "\n=========== MENU ===========" << std::endl;
		std::cout << "Choose solution leetcode to run:\n";
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Two Sum\n";
		std::cout << "2. Add Two Numbers (Linked List)\n";
		std::cout << "3. Longest Substring Without Repeating Char\n";
		std::cout << "4. Median Sorted Arrays\n";
		std::cout << "5. Longest Panlindromic\n";
		std::cout << "6.Zigzag Conversion\n";
		std::cout << "============================" << std::endl;
		std::cout << "Your Choice: ";
		std::cin >> choice;

		switch (choice) {
			case 0: 
				std::cout << "Good bye!\n";
				return 0;
			case 1: runTwoSum(); break;
			case 2: runAddTwoNumbers(); break;
			case 3: runLengthOfLongestSubstring(); break;
			case 4: runMedianSortedArrays(); break;
			case 5: runLongestPalindromic(); break;
			case 6: runZigzagConversion(); break;
		default: std::cout << "Invalid choice.\n"; break;
		}
		
		char cont;
		std::cout << "\nDo you want to continue? (Y/N): ";
		std::cin >> cont;

		if (std::toupper(cont) != 'Y') {
			std::cout << "EXIT PROGRAM.\n";
			break;
		}
	}
	
	return 0;
}