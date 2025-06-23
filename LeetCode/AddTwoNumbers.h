#pragma once
#ifndef ADDTWONUMBER_H
#define ADDTWONUMBER_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

//Tiện ích tạo list từ mảng
ListNode* createList(int arr[], int size);

//In linked list
void printList(ListNode* head);
#endif // !ADDTWONUMBER_H
