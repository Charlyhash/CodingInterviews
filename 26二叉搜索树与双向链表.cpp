/*
��ָoffer-26������������˫������
��Ŀ���⣺
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

����˼·��

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