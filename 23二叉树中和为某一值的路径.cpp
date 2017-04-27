/*
����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/

#include <iostream>
#include <vector>
#include <stack>
#include "TreeInclude.h"

using namespace std;

class Solution {
public:
	vector<vector<int> > FindPath1(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<int> v;
		ThePath(ret, v, root, expectNumber);

		return ret;
	}

public: 
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		stack<TreeNode*> s;
		vector<int> v;
		TreeNode* cur = root;
		int sum = 0;
		s.push(root);
		TreeNode* last = NULL;
		while (!s.empty())
		{
			if (cur == NULL)
			{
				TreeNode* tmp = s.top();
				if (tmp->right != NULL && tmp->right != last)
					cur = tmp->right;
				else
				{
					last = tmp;
					s.pop();
					v.pop_back();
					sum -= tmp->val;
				}
			}
			else
			{
				s.push(cur);
				sum += cur->val;
				v.push_back(cur->val);
				if (cur->left == NULL && cur->right == NULL && sum == expectNumber)
					ret.push_back(v);
				cur = cur->left;
			}

		}

		return ret;
	}

private:
	void ThePath(vector<vector<int>>& ret, vector<int>& v, TreeNode* root, int sum)
	{
		if (root == NULL)
			return;
		v.push_back(root->val);
		if (root->left == NULL && root->right == NULL && sum == root->val)
			ret.push_back(v);
		else
		{
			if (root->left)
				ThePath(ret, v, root->left, sum - root->val);
			if (root->right)
				ThePath(ret, v, root->right, sum - root->val);
		}
		//���ظ��ڵ�ʱ��ɾ��·���ϵĵ�ǰ�ڵ�ֵ��
		v.pop_back();
	}
};

int main()
{
	vector<int> r{ 10,5,12,4,7 };
	TreeNode* root = CreateTree(r);
	Solution sol;
	vector<vector<int>> ret = sol.FindPath(root, 22);

	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}