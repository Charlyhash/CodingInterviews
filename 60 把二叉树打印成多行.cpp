/*
剑指offer:把二叉树打印成多行

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

解题思路：
层次遍历二叉树：用一个队列保存访问的节点，队列的容量即为当层要节点数目。读取完后，
继续遍历下一层
*/

#include <iostream>
#include <vector>
#include "TreeInclude.h"
#include <queue>
using namespace std;

//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :val(x), left(NULL), right(NULL) {	}
//};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> ret;
		if (pRoot == NULL)
			return ret;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			int total = q.size();
			int count = 0;
			vector<int> v;
			while (count++ < total)
			{
				TreeNode* p = q.front(); q.pop();
				v.push_back(p->val);
				if (p->left)
					q.push(p->left);
				if (p->right)
					q.push(p->right);
			}
			ret.push_back(v);
		}

		return ret;
	}
};

int main()
{
	vector<int> v{ 8,6,10,5,7,9,11 };
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