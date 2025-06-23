#include <iostream>
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // node giả để dễ thao tác
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

        return dummy->next; // bỏ node giả
    }
};

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

int main() {
	int arr1[] = {2, 4, 3};
	int arr2[] = {5, 6, 4};
	ListNode* l1 = createList(arr1, 3);
	ListNode* l2 = createList(arr2, 3);
	Solution sol;
	ListNode* result = sol.addTwoNumbers(l1, l2);
	
	std::cout << "Kết quả cộng: ";
	printList(result);

	return 0;
}