/*
剑指offer-反转链表

输入一个链表，反转链表后，输出链表的所有元素。

解题思路：
*/

#include <iostream>
#include <vector>
#include "ListNodeHead.h"

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return pHead;
		ListNode* dummy = new ListNode(-1);
		dummy->next = pHead;
		ListNode* p = pHead;
		ListNode* tmp;
		ListNode* next;
		while (p->next)
		{
			next = p->next->next;
			tmp = dummy->next;
			dummy->next = p->next;
			dummy->next->next = tmp;
			p->next = next;
		}

		return dummy->next;
	}
};

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	ListNode* l = CreateList(v);
	PrintList(l);
	Solution sol;
	ListNode* ret = sol.ReverseList(l);
	PrintList(ret);

	return 0;
}