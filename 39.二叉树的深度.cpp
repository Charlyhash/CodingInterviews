/*
��ָoffer �����������
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

����˼·��

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
	}
};