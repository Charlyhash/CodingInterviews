/*
剑指offer 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列
{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

解题思路：先序遍历的第一个数val将中序遍历的数组分为两个部分，左边
为左子树的组成，右边组成右子树。然后根据左右子树的数目，得到先
序遍历的的左右子树。该val构造为一个根节点，左右子树分别递归调用该
函数，之后返回根节点即可。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "TreeInclude.h"
using namespace std;

class Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		if (pre.size() == 0)
			return nullptr;
		if (pre.size() == 1)
		{
			TreeNode* node = new TreeNode(pre[0]);
			return node;
		}
		TreeNode* ret = new TreeNode(pre[0]);
		int index;
		int i;
		for (i = 0; i < vin.size(); ++i)
		{
			if (vin[i] == pre[0])
			{
				index = i;
				break;
			}
		}
		vector<int> preLeft;
		vector<int> preRight;
		vector<int> vinLeft;
		vector<int> vinRight;
		for (i = 0; i < index; ++i)
			vinLeft.push_back(vin[i]);
		for (i = index + 1; i < vin.size(); ++i)
			vinRight.push_back(vin[i]);
		for (i = 1; i <= index; ++i)
			preLeft.push_back(pre[i]);
		for (i = index+1; i < pre.size(); ++i)
			preRight.push_back(pre[i]);
		ret->left = reConstructBinaryTree(preLeft, vinLeft);
		ret->right = reConstructBinaryTree(preRight, vinRight);

		return ret;
	}
};

void TEST()
{
	vector<int> pre{ 1,2,4,7,3,5,6,8 };
	vector<int> vin{ 4,7,2,1,5,3,8,6 };
	Solution sol;
	TreeNode* root = sol.reConstructBinaryTree(pre, vin);
	FirstOrderTraverse(root);
	cout << endl;
	cout << "-----------------------" << endl;

}

int main()
{
	TEST();

	return 0;
}