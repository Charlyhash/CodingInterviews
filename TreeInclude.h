#ifndef _TREE_INCLUDE_H_ 
#define _TREE_INCLUDE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// 节点数据结构
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//使用数组创建二叉树
void CreateNode(const vector<int>& v, TreeNode* cur, int curIndex)
{
	int len = v.size();
	if (len == 0 || cur == NULL || curIndex < 0 || curIndex >= len)
		return;

	if ((2 * curIndex + 1 < len) && (v[2*curIndex+1] != -1))
	{
		TreeNode* tmp = new TreeNode(v[2 * curIndex + 1]);
		cur->left = tmp;
	}
	else
		cur->left = NULL;
	if ((2 * curIndex + 2 < len) && (v[2*curIndex+2] != -1))
	{
		TreeNode* tmp = new TreeNode(v[2 * curIndex + 2]);
		cur->right = tmp;
	}
	else
		cur->right = NULL;
	CreateNode(v, cur->left, 2 * curIndex + 1);
	CreateNode(v, cur->right, 2 * curIndex + 2);
}

TreeNode* CreateTree(const vector<int>& v)
{
	int len = v.size();
	if (len == 0)
		return NULL;

	TreeNode* root = new TreeNode(v[0]);
	CreateNode(v, root, 0);

	return root;
}

void FirstOrderTraverse(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";
	FirstOrderTraverse(root->left);
	FirstOrderTraverse(root->right);
	//cout << endl;
}

void FirstOrderTraverseIter(TreeNode* root)
{
	stack<TreeNode*> stk;
	TreeNode* p = root;
	while (p || !stk.empty())
	{
		while (p)
		{
			cout << p->val << " ";
			stk.push(p);
			p = p->left;
		}
		if (!stk.empty())
		{
			p = stk.top(); stk.pop();
			p = p->right;
		}
	}

	cout << endl;
}

void InorderTraverse(TreeNode* root)
{
	TreeNode* p = root;
	if (p == NULL)
		return;
	InorderTraverse(p->left);
	cout << p->val << " ";
	InorderTraverse(p->right);
}

void InorderTraverseIter(TreeNode* root)
{
	TreeNode* p = root;
	stack<TreeNode*> s;

	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top(); s.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
	cout << endl;
}

void PostorderTraverse(TreeNode* root)
{
	TreeNode* p = root;
	if (p == NULL)
		return;
	PostorderTraverse(p->left);
	PostorderTraverse(p->right);
	cout << p->val << " ";
}

void PostorderTraverseIter(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* p = root;
	TreeNode* visited = NULL;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}

		if (!s.empty())
		{
			p = s.top();
			//p has no right child or p.right has visited
			if (p->right == NULL || p->right == visited)
			{
				cout << p->val << " ";
				visited = p;
				s.pop();
				p = NULL;
			}
			else
				p = p->right;

		}
	}
}

void MakeEmpty(TreeNode* root)
{
	if (root != NULL)
	{
		MakeEmpty(root->left);
		MakeEmpty(root->right);
		delete root;
	}
}

#endif // 
