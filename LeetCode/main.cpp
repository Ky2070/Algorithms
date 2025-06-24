#include <iostream>
#include <vector>
#include <cctype>
#include <random>
#include "TwoSum.h"
#include "AddTwoNumbers.h"
//Tạo hàm thực thi riêng cho từng bài

void runTwoSum() {
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