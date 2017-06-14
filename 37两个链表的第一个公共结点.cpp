/*
剑指offer：两个链表的第一个公共结点
题目描述：
输入两个链表，找出它们的第一个公共结点。
解题思路：先比较链表长度，然后对从剩余相同的长度开始遍历，找到第一个公共节点就返回
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