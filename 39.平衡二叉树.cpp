/*
剑指offer:平衡二叉树
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeInclude.h"
using namespace std;

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
	//判断是否为平衡树,并记录当前的深度 pDepth
	bool IsBalanced(TreeNode* pRoot, int* pDepth)
	{
		if (pRoot == NULL)
		{
			*pDepth = 0;
			return true;
		}
		int left = 0, right = 0;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				*pDepth = max(left, right) + 1;
				return true;
			}
		}

		return false;
	}
};

int main()
{
	//tree
	vector<int> t{1,2,3,4,5,-1,6,-1,-1,7};
	TreeNode* pRoot = CreateTree(t);
	Solution sol;
	cout << sol.IsBalanced_Solution(pRoot) << endl;

	return 0;
}