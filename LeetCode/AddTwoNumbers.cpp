#include <iostream>
#include "AddTwoNumbers.h"

ListNode* Solution1::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* dummy = new ListNode(); //Tạo node giả dễ thao tác
	ListNode* curr = dummy;
	int carry = 0;

	while (l1 != nullptr || l2 != nullptr || carry > 0) {
		int val1 = (l1 != nullptr) ? l1->val : 0;
		int val2 = (l2 != nullptr) ? l2->val : 0;

		int sum = val1 + val2 + carry;
		int digit = sum % 10;
		carry = sum / 10;

		curr->next = new ListNode(digit);
		curr = curr->next;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	return dummy->next;
}

//Hàm tiện ích tạo linked list từ mảng
ListNode* createList(int arr[], int size){
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	
	for (int i = 0; i < size; i++){
	   ListNode* newNode = new ListNode(arr[i]);
	   if (!head){
	      head = tail = newNode;
	   } else {
	      tail->next = newNode;
	      tail = tail->next;
	   }
	}
	return head;
}

//In linked list
void printList(ListNode* head){
	while(head != nullptr){
	  std::cout << head->val;
	  if (head->next) std::cout << " -> ";
	  head = head->next;
	}
	std::cout << std::endl;
}