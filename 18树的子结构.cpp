/*
剑指offer-树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）

解题思路：递归查找。
先实现一个函数IsSubtree(TreeNode* p1, TreeNode* p2)判断p2是不是p1的子树。
该函数可以用递归来实现：首先该节点的值相等，然后分别判断左右子树。然后只需：
pRoot2为pRoot1的子树以及递归判断pRoot1的左右子树。
*/

#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;

		return IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

	bool IsSubtree(TreeNode* p1, TreeNode* p2)
	{
		if (p2 == NULL) //变量到p2为空，说明前面对应节点的value都相等了
			return true;
		if (p1 == NULL) //p2!=NULL
			return false;
		if (p1->val == p2->val)
			return IsSubtree(p1->left, p2->left) && IsSubtree(p1->right, p2->right);
		else
			return false;
	}
};

int main()
{
	vector<int> vb{ 8, 9, 2 };
	vector<int> va{8, 8, 7, 9, 2, -1, -1, -1, -1, 4, 7};
	TreeNode* p1 = CreateTree(va);
	TreeNode* p2 = CreateTree(va);
	Solution sol;
	cout << sol.HasSubtree(p1, p2) << endl;


}