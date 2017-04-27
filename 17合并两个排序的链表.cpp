/*
剑指offer-合并两个排序的链表

输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/

#include <iostream>
#include <vector>
#include "ListNodeHead.h"

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode* p1 = pHead1; ListNode* p2 = pHead2;
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val <= p2->val)
			{
				p->next = p1;
				p = p->next;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				p = p->next;
				p2 = p2->next;
			}
		}
		if (p1 == NULL)
			p->next = p2;
		if (p2 == NULL)
			p->next = p1;

		return dummy->next;
	}
};

int main()
{
	Solution sol;
	vector<int> v1{ 1,3,4,5 };
	vector<int> v2{ 1,2,4,7, 8 };
	ListNode* head1 = CreateList(v1);
	ListNode* head2 = CreateList(v2);
	ListNode* ret = sol.Merge(head1, head2);

	PrintList(ret);
}