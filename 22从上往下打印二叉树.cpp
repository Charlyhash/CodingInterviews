/*
��ָoffer-�������´�ӡ������

�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

����˼·�����Ĳ�α�����BFS.
һ�㣬BFS��Ҫά��һ�����С��������������ݽṹ���ȳ����У�
Ȼ�����������ӽڵ�����С�
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