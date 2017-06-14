/*
剑指offer:二叉树的下一个结点

题目描述:
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中
的结点不仅包含左右子结点，同时包含指向父结点的指针。

解题思路：
分3种情况：
(1)如果有右子树，那么为右子树最左边的节点
(2)没有右子树，且是父节点的左节点，那么其为父节点
(3)如果没有右子树且为父节点的右节点，那么一直向上查找，直到该节点为父节点的左子树，
那么这个节点的父节点就为所求
*/

#include <iostream>
using namespace std;

struct TreeLinkNode 
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			TreeLinkNode* p = pNode->right;
			while (p->left != NULL)
				p = p->left;
			return p;
		}
		while (pNode->next != NULL)
		{
			//找到第一个父节点，该节点为其父节点的左子节点
			TreeLinkNode* p = pNode->next;
			if (p->left == pNode)
				return p;
			pNode = p;
		}

		return NULL;
	}
};