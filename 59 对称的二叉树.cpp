/*
剑指offer:对称的二叉树

题目描述：
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的
镜像是同样的，定义其为对称的。

解题思路：
左子树和右子树相同
*/

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return help(pRoot, pRoot);
	}

	bool help(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
			return true;
		if (left == NULL || right == NULL)
			return false;
		if (left->val == right->val)
			return help(left->left, right->right) && help(left->right, right->left);

		return false;
	}
};