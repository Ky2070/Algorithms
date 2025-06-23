#include <iostream>
#include <vector>
#include <cctype>
#include "TwoSum.h"
#include "AddTwoNumbers.h"
//Tạo hàm thực thi riêng cho từng bài

void runTwoSum() {
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	Solution sol;
	std::vector<int> result = sol.twoSum(nums, target);
	std::cout << "Indices found: ";
	for (int index : result) {
		std::cout << index << " ";
	}

	std::cout << std::endl;
}

void runAddTwoNumbers() {
	int arr1[] = { 2, 4, 3 };
	int arr2[] = { 5, 6, 4 };

	ListNode* l1 = createList(arr1, 3);
	ListNode* l2 = createList(arr2, 3);

	Solution1 sol1;
	ListNode* result = sol1.addTwoNumbers(l1, l2);

	std::cout << "Result of addition: ";
	printList(result);
}
int main() {
	while (true) {
		int choice;
		std::cout << "\n=========== MENU ===========" << std::endl;
		std::cout << "Choose solution leetcode to run:\n";
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Two Sum\n";
		std::cout << "2. Add Two Numbers (Linked List)\n";
		std::cout << "============================" << std::endl;
		std::cout << "Your Choice: ";
		std::cin >> choice;

		switch (choice) {
			case 0: 
				std::cout << "Good bye!\n";
				return 0;
			case 1: runTwoSum(); break;
			case 2: runAddTwoNumbers(); break;
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