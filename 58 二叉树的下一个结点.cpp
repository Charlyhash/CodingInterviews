/*
��ָoffer:����������һ�����

��Ŀ����:
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬����
�Ľ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

����˼·��
��3�������
(1)���������������ôΪ����������ߵĽڵ�
(2)û�������������Ǹ��ڵ����ڵ㣬��ô��Ϊ���ڵ�
(3)���û����������Ϊ���ڵ���ҽڵ㣬��ôһֱ���ϲ��ң�ֱ���ýڵ�Ϊ���ڵ����������
��ô����ڵ�ĸ��ڵ��Ϊ����
*/

#include <iostream>
using namespace std;

struct TreeLinkNode 
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			TreeLinkNode* p = pNode->right;
			while (p->left != NULL)
				p = p->left;
			return p;
		}
		while (pNode->next != NULL)
		{
			//�ҵ���һ�����ڵ㣬�ýڵ�Ϊ�丸�ڵ�����ӽڵ�
			TreeLinkNode* p = pNode->next;
			if (p->left == pNode)
				return p;
			pNode = p;
		}

		return NULL;
	}
};