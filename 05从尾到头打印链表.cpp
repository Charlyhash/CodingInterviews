/*
��ָoffer
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

����˼·��
1.�ŵ�һ��vector�У�Ȼ��reverse;
2.ʹ��ջ���ÿһ���ڵ㣬Ȼ��ջ�е�Ԫ�����
3.DFS
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct ListNode {
      int val;
       struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
 };

ListNode* Create(vector<int>& v)
{
	ListNode* dummy = new ListNode(0);
	ListNode* p = dummy;
	for (auto i : v)
	{
		ListNode* tmp = new ListNode(i);
		p->next = tmp;
		p = p->next;
	}

	return dummy->next;
}

void Print(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

}

void PrintVec(vector<int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
 
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (head == NULL)
			return res;

		//����vector��Ȼ��reverse
		ListNode* p = head;
		while (p != NULL)
		{
			res.push_back(p->val);
			p = p->next;
		}

		reverse(res.begin(), res.end());

		return res;
	}

	vector<int> printListFromTailToHead1(ListNode* head)
	{
		vector<int> ret;
		if (head == NULL)
			return ret;
		ListNode* p = head;
		stack<ListNode*> nodeStack;
		while (p != NULL)
		{
			nodeStack.push(p);
			p = p->next;
		}
		while (nodeStack.size() > 0)
		{
			ListNode* tmp = nodeStack.top();
			ret.push_back(tmp->val);
			nodeStack.pop();
		}

		return ret;
	}

	vector<int> printListFromTailToHead2(ListNode* head)
	{
		vector<int> ret;
		ListNode* p = head;
		if (head == NULL)
			return ret;
		DFS(p, ret);

		return ret;
	}

	void DFS(ListNode* p, vector<int>& ret)
	{
		if (p != NULL)
		{
			DFS(p->next, ret);
			ret.push_back(p->val);
		}
	}
};

void TEST()
{
	Solution sol;
	vector<int> v{ 1,2,3,4,5 };
	ListNode* head = Create(v);
	//Print(head);
	vector<int> ret = sol.printListFromTailToHead2(head);
	PrintVec(ret);
}

int main()
{
	TEST();
}