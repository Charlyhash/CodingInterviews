/*
��ָoffer:�ԳƵĶ�����

��Ŀ������
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶�������
������ͬ���ģ�������Ϊ�ԳƵġ�

����˼·��
����������������ͬ
*/

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return help(pRoot, pRoot);
	}

	bool help(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
			return true;
		if (left == NULL || right == NULL)
			return false;
		if (left->val == right->val)
			return help(left->left, right->right) && help(left->right, right->left);

		return false;
	}
};