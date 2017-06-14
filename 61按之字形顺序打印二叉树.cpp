/*
��ָoffer:��֮����˳���ӡ������

��Ŀ����:
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ���
�����˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

����˼·��
������ջ����ڵ㣬s1���ڴ��������ڵ㣬s2���ڴ��ż�����ڵ㡣������������ڵ�ʱ��
Ӧ���Ƚ����ӽڵ���뵽s2�У�Ȼ������ӽڵ㣻����s2ʱ��Ӧ���ȷ����ӽڵ㣬�ٷ����ӽڵ㡣
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