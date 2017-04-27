/*
剑指offer-从上往下打印二叉树

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

解题思路：树的层次遍历，BFS.
一般，BFS需要维护一个队列。对于树这种数据结构，先出队列，
然后让其左右子节点入队列。
*/

#include <iostream>
#include <vector>
#include <queue>
#include "TreeInclude.h"

using namespace std;

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (!root)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* cur;
		while (!q.empty())
		{
			cur = q.front(); q.pop();
			if (cur == NULL)
				continue;
			ret.push_back(cur->val);
			q.push(cur->left);
			q.push(cur->right);
		}

		return ret;
	}
};


int main()
{
	vector<int> v{ 3,2,5,1,-1,7,8 };
	TreeNode* root = CreateTree(v);
	Solution sol;
	vector<int> ret = sol.PrintFromTopToBottom(root);

	for (auto i : ret)
		cout << i << " ";
	return 0;
}