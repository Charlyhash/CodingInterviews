/*
��ָoffer-��������ĸ���

����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����
һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ�
�������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã���
����������ֱ�ӷ��ؿգ�

����˼·��

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "ListNodeHead.h"

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* ret;
		//oldnode->newnode
		unordered_map<RandomListNode*, RandomListNode*> umap;
		RandomListNode* p = pHead;
		ret = new RandomListNode(p->label);
		umap[p] = ret;
		p = p->next;
		RandomListNode* cur = ret;
		RandomListNode* tmp;
		while (p != NULL)
		{
			tmp = new RandomListNode(p->label);
			umap[p] = tmp;
			cur->next = tmp;
			cur = cur->next;
			p = p->next;
		}
		cur = ret;
		p = pHead;
		while (cur != NULL)
		{
			cur->random = umap[p->random];
			cur = cur->next;
			p = p->next;
		}

		return ret;
	}

	RandomListNode* Clone1(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSibling(pHead);

		return ReconnectionNodes(pHead);
	}

private:
	void CloneNodes(RandomListNode* pHead)
	{
		RandomListNode *pNode = pHead;
		while (pNode != NULL)
		{
			RandomListNode* pCloneNode = new RandomListNode(pNode->label);
			pCloneNode->next = pNode->next;
			pCloneNode->random = NULL;
			pNode->next = pCloneNode;
			pNode = pCloneNode->next;
		}
	}
	
	void ConnectSibling(RandomListNode* pHead)
	{
		RandomListNode* pNode = pHead;
		while (pNode != NULL)
		{
			RandomListNode *pCloned = pNode->next;
			if (pNode->random != NULL)
			{
				pCloned->random = pNode->random->next;
				
			}
			pNode = pCloned->next;
		}
	}

	RandomListNode* ReconnectionNodes(RandomListNode* pHead)
	{
		RandomListNode* pNode = pHead;
		RandomListNode* pCloneHead = NULL;
		RandomListNode* pCloneNode = NULL;
		if (pNode != NULL)
		{
			pCloneHead = pNode->next;
			pCloneNode = pNode->next;
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}
		while (pNode != NULL)
		{
			pCloneNode->next = pNode->next;
			pCloneNode = pCloneNode->next;
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}

		return pCloneHead;
	}

};