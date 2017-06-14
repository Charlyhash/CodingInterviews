/*
��ָoffer����������ĵ�һ���������
��Ŀ������
�������������ҳ����ǵĵ�һ��������㡣
����˼·���ȱȽ������ȣ�Ȼ��Դ�ʣ����ͬ�ĳ��ȿ�ʼ�������ҵ���һ�������ڵ�ͷ���
*/

#include <iostream>
#include <vector>
#include "ListNodeHead.h"
using namespace std;

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		size_t len1 = lengthOfList(pHead1);
		size_t len2 = lengthOfList(pHead2);
		size_t diffLen = len1 - len2;
		ListNode* pLong = pHead1; ListNode* pShort = pHead2;
		if (len2 > len1)
		{
			pLong = pHead2;
			pShort = pHead1;
			diffLen = len2 - len1;
		}
		while (diffLen--)
			pLong = pLong->next;
		while (pLong && pShort && pLong != pShort)
		{
			pLong = pLong->next;
			pShort = pShort->next;
		}

		return pLong;
	}
private:
	size_t lengthOfList(ListNode* p)
	{
		size_t ret = 0;
		while (p != NULL)
		{
			++ret;
			p = p->next;
		}

		return ret;
	}
};