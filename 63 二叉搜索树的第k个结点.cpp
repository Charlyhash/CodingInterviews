/*
剑指offer 二叉搜索树的第k个结点

题目描述：
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 
		 5 
		/ \ 
	   3   7 
	  /\   /\ 
	 2  4 6  8 
中，按结点数值大小顺序第三个结点的值为4。

解题思路：中序遍历中第k次遍历到的节点即为第k大的节点
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