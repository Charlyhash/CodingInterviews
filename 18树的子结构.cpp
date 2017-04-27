/*
��ָoffer-�����ӽṹ

�������ö�����A��B���ж�B�ǲ���A���ӽṹ��
��ps������Լ��������������һ�������ӽṹ��

����˼·���ݹ���ҡ�
��ʵ��һ������IsSubtree(TreeNode* p1, TreeNode* p2)�ж�p2�ǲ���p1��������
�ú��������õݹ���ʵ�֣����ȸýڵ��ֵ��ȣ�Ȼ��ֱ��ж�����������Ȼ��ֻ�裺
pRoot2ΪpRoot1�������Լ��ݹ��ж�pRoot1������������
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
		if (p2 == NULL) //������p2Ϊ�գ�˵��ǰ���Ӧ�ڵ��value�������
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