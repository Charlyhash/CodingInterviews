/*
剑指offer-二叉树的镜像

操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树
8
/  \
6   10
/ \  / \
5  7 9 11
镜像二叉树
8
/  \
10   6
/ \  / \
11 9 7  5

解题思路:通过以上的图分析，要求镜像二叉树，需要先交换左右子节点，
然后求左右子树的镜像。直到根节点为空或者左右子节点为空
*/


#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		
		if (pRoot == NULL)
			return;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return;
		else
		{
			TreeNode* tmp;
			tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};

int main()
{
	vector<int> v{ 8,6,10,5,7,9,11 };
	Solution sol;
	TreeNode* p = CreateTree(v);
	FirstOrderTraverseIter(p);
	sol.Mirror(p);
	FirstOrderTraverseIter(p);

	return 0;
}