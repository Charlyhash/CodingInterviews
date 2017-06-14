/*
剑指offer:按之字形顺序打印二叉树

题目描述:
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右
至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

解题思路：
用两个栈保存节点，s1用于存放奇数层节点，s2用于存放偶数个节点。遍历存放奇数节点时，
应该先将左子节点放入到s2中，然后放右子节点；遍历s2时，应该先放右子节点，再放左子节点。
*/


#include <iostream>
#include <vector>
#include <stack>
#include "TreeInclude.h"
using namespace std;

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> ret;
		if (pRoot == NULL)
			return ret;
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		TreeNode* node;
		s1.push(pRoot);
		while (!s1.empty() || !s2.empty())
		{		
			if (!s1.empty())
			{
				vector<int> data;
				while (!s1.empty())
				{
					node = s1.top(); s1.pop();
					data.push_back(node->val);
					if (node->left != NULL)
						s2.push(node->left);
					if (node->right != NULL)
						s2.push(node->right);
				}
				ret.push_back(data);
			}

			if (!s2.empty())
			{
				vector<int> data;
				while (!s2.empty())
				{
					node = s2.top(); s2.pop();
					data.push_back(node->val);
					if (node->right != NULL)
						s1.push(node->right);
					if (node->left != NULL)
						s1.push(node->left);
				}
				ret.push_back(data);
			}
		}

		return ret;
	}
};

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	TreeNode* pRoot = CreateTree(v);
	Solution sol;
	vector<vector<int>> ret = sol.Print(pRoot);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}