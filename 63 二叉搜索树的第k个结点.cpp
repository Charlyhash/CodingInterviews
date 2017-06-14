/*
��ָoffer �����������ĵ�k�����

��Ŀ������
����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣���磬 
		 5 
		/ \ 
	   3   7 
	  /\   /\ 
	 2  4 6  8 
�У��������ֵ��С˳�����������ֵΪ4��

����˼·����������е�k�α������Ľڵ㼴Ϊ��k��Ľڵ�
*/

#include <iostream>
#include <vector>
#include <stack>
#include "TreeInclude.h"
using namespace std;

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot)
		{
			TreeNode *ret = KthNode(pRoot->left, k);
			if (ret)
				return ret;
			if (++count == k)
				return pRoot;
			ret = KthNode(pRoot->right, k);
			if (ret)
				return ret;
		}

		return NULL;
	}

	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		int cnt = 0;
		TreeNode* p = pRoot;
		stack<TreeNode*> s;
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			TreeNode* node = s.top(); s.pop();
			if (++cnt == k)
				return node;
			p = node->right;
		}
		
		return NULL;
	}

private:
	int count = 0;
};