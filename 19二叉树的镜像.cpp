/*
��ָoffer-�������ľ���

���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺Դ������
8
/  \
6   10
/ \  / \
5  7 9 11
���������
8
/  \
10   6
/ \  / \
11 9 7  5

����˼·:ͨ�����ϵ�ͼ������Ҫ�������������Ҫ�Ƚ��������ӽڵ㣬
Ȼ�������������ľ���ֱ�����ڵ�Ϊ�ջ��������ӽڵ�Ϊ��
*/


#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		
		if (pRoot == NULL)
			return;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return;
		else
		{
			TreeNode* tmp;
			tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};

int main()
{
	vector<int> v{ 8,6,10,5,7,9,11 };
	Solution sol;
	TreeNode* p = CreateTree(v);
	FirstOrderTraverseIter(p);
	sol.Mirror(p);
	FirstOrderTraverseIter(p);

	return 0;
}