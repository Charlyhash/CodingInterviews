/* 
��ָoffer-�����е�����k�����
����һ����������������е�����k����㡣

����˼·��Ҫ����k���������ȵ����

*/
#include <iostream>
#include <vector>
#include "ListNodeHead.h"
using namespace std;

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0)
			return NULL;
		ListNode* p2 = pListHead;
		ListNode* p1 = pListHead;

		for (int i = 1; i < k; ++i)
		{
			if (p1->next != NULL)
				p1 = p1->next;
			else
				return NULL;
		}

		while (p1->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		return p2;
	}
};

int main()
{
	vector<int> v{1,2,3,4,5};
	ListNode* head = CreateList(v);
	PrintList(head);
	Solution sol;
	for (int i = 1; i < 20; ++i)
	{
		ListNode* ret = sol.FindKthToTail(head, i);
		if (ret == NULL)
			cout << "NULL" << endl;
		else
			cout << ret->val << endl;
	}

	return 0;
}