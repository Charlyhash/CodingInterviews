#ifndef __LIST_NODE_HEAD_H__
#define __LIST_NODE_HEADS_H__

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//打印链表
void PrintList(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

//用一个vector创建链表，返回链表头
ListNode* CreateList(vector<int> v)
{
	ListNode* head = nullptr;
	if (v.size() == 0)
		return head;
	head = new ListNode(v[0]);
	ListNode* cur = head;
	ListNode* next = nullptr;

	for (size_t i = 1; i < v.size(); ++i)
	{
		ListNode* tmp = new ListNode(v[i]);
		cur->next = tmp;
		cur = tmp;
	}

	//PrintList(head);

	return head;
}

//获取中间的节点
//奇数个节点为中间的节点，偶数个节点为n/2位置的节点
ListNode* GetMiddle(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* lower = head;
	ListNode* faster = head;
	while (faster->next != nullptr && faster->next->next != nullptr)
	{
		lower = lower->next;
		faster = faster->next->next;
	}
	//if (faster->next != nullptr)

	//cout << lower->val << endl;
	return lower;
}

//逆序一个链表
ListNode* ReverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* cur = head->next;
	ListNode* pre = head;
	pre->next = nullptr;
	ListNode* next = nullptr;
	while (cur != nullptr)
	{
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}

	return pre;
}

//删除链表中的p
ListNode* ListRemove(ListNode* head, ListNode* p)
{
	ListNode* p1 = head;
	if (p == head) //头结点
	{
		head = head->next;
		delete p1;
		return head;
	}
	while (p1->next != p)
	{
		p1 = p1->next;
	}

	//ListNode* tmp = p1->next;
	p1->next = p1->next->next;
	delete p;

	return head;

}

#endif