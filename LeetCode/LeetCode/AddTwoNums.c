#include <stdio.h>
#include <malloc.h>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* res = malloc(sizeof(struct ListNode));
	res->next = 0;
	struct ListNode* temp = res;
	int quotient = 0;
	while ((p1 || p2 || quotient))
	{
		temp->next = malloc(sizeof(struct ListNode));
		temp = temp->next;
		temp->next = 0;
		int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + quotient;
		temp->val = sum % 10;
		quotient = sum / 10;
		p1 = p1 ? p1->next : 0;
		p2 = p2 ? p2->next : 0;
		
	}
	temp = res;
	res = res->next;
	free(temp);
	return res;
}


struct ListNode* getNodeList(int* arr, int length) {
	struct ListNode* res = 0;
	struct ListNode* pre = 0;
	struct ListNode* temp = 0;
	for (int i = 0; i < length; i++) {
		temp = malloc(sizeof(struct ListNode));
		temp->val = arr[i];
		temp->next = 0;
		if (pre) {
			pre->next = temp;
			pre = temp;
		}
		else
		{
			pre = temp;
			res = pre;
		}
	}
	return res;
}


int main() {
	int arr1[] = {1};
	int arr2[] = {9, 9};
	struct ListNode* l1 = getNodeList(arr1, 1);
	struct ListNode* l2 = getNodeList(arr2, 2);

	struct ListNode* res = addTwoNumbers(l1, l2);
	if (res) {
		while (res)
		{
			printf("%d", res->val);
			if (res->next) {
				printf(" -> ");
			}
			res = res->next;
		}
		free(res);
		free(l1);
		free(l2);
	}
	return 0;
}