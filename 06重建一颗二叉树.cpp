/*
��ָoffer �ؽ�������
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������
{4,7,2,1,5,3,8,6}�����ؽ������������ء�

����˼·����������ĵ�һ����val����������������Ϊ�������֣����
Ϊ����������ɣ��ұ������������Ȼ�����������������Ŀ���õ���
������ĵ�������������val����Ϊһ�����ڵ㣬���������ֱ�ݹ���ø�
������֮�󷵻ظ��ڵ㼴�ɡ�
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "TreeInclude.h"
using namespace std;

class Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		if (pre.size() == 0)
			return nullptr;
		if (pre.size() == 1)
		{
			TreeNode* node = new TreeNode(pre[0]);
			return node;
		}
		TreeNode* ret = new TreeNode(pre[0]);
		int index;
		int i;
		for (i = 0; i < vin.size(); ++i)
		{
			if (vin[i] == pre[0])
			{
				index = i;
				break;
			}
		}
		vector<int> preLeft;
		vector<int> preRight;
		vector<int> vinLeft;
		vector<int> vinRight;
		for (i = 0; i < index; ++i)
			vinLeft.push_back(vin[i]);
		for (i = index + 1; i < vin.size(); ++i)
			vinRight.push_back(vin[i]);
		for (i = 1; i <= index; ++i)
			preLeft.push_back(pre[i]);
		for (i = index+1; i < pre.size(); ++i)
			preRight.push_back(pre[i]);
		ret->left = reConstructBinaryTree(preLeft, vinLeft);
		ret->right = reConstructBinaryTree(preRight, vinRight);

		return ret;
	}
};

void TEST()
{
	vector<int> pre{ 1,2,4,7,3,5,6,8 };
	vector<int> vin{ 4,7,2,1,5,3,8,6 };
	Solution sol;
	TreeNode* root = sol.reConstructBinaryTree(pre, vin);
	FirstOrderTraverse(root);
	cout << endl;
	cout << "-----------------------" << endl;

}

int main()
{
	TEST();

	return 0;
}