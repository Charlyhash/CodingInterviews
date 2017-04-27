/*
剑指offer-26二叉搜索树与双向链表
题目大意：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

解题思路：

*/

#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;

		if (!pRootOfTree->left && !pRootOfTree->right)
			return pRootOfTree;

		TreeNode* leftConverNode = Convert(pRootOfTree->left);
		TreeNode* rightConverNode = Convert(pRootOfTree->right);

		TreeNode* p = leftConverNode;
		if (p != NULL)
		{
			while (p->right != NULL)
				p = p->right;
			p->right = pRootOfTree;
			pRootOfTree->left = p;
			if (rightConverNode != NULL)
			{
				pRootOfTree->right = rightConverNode;
				rightConverNode->left = pRootOfTree;
			}
			else
				pRootOfTree->right = NULL;
		}
		else
		{
			leftConverNode = pRootOfTree;
			pRootOfTree->left = NULL;
			if (rightConverNode != NULL)
			{
				pRootOfTree->right = rightConverNode;
				rightConverNode->left = pRootOfTree;
			}
			else
				pRootOfTree->right = NULL;
		}

		return leftConverNode;

	}
};