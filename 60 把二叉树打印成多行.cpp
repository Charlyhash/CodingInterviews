/*
��ָoffer:�Ѷ�������ӡ�ɶ���

��Ŀ����
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�

����˼·��
��α�������������һ�����б�����ʵĽڵ㣬���е�������Ϊ����Ҫ�ڵ���Ŀ����ȡ���
����������һ��
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