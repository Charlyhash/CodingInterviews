/*
剑指offer:序列化二叉树

题目描述:请实现两个函数，分别用来序列化和反序列化二叉树
解题思路：
*/

#include <iostream>
#include <vector>
#include <queue>
#include "TreeInclude.h"
using namespace std;

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	char* Serialize(TreeNode *root) {
		buff.clear();
		SerializeDFS(root);
		int *ret = new int[buff.size()];
		for (size_t i = 0; i < buff.size(); ++i)
			ret[i] = buff[i];
		return (char*)ret;
	}
	TreeNode* Deserialize(char *str) {
		int *p = (int*)str;
		return DeserializeDFS(p);
	}

private:
	vector<int> buff;
	void SerializeDFS(TreeNode* root)
	{
		if (root == NULL)
			buff.push_back(0xaaaa);
		else
		{
			buff.push_back(root->val);
			SerializeDFS(root->left);
			SerializeDFS(root->right);
		}
	}

	TreeNode* DeserializeDFS(int* &p)
	{
		if (*p == 0xaaaa)
		{
			++p;
			return NULL;
		}
		TreeNode* ret = new TreeNode(*p);
		++p;
		ret->left = DeserializeDFS(p);
		ret->right = DeserializeDFS(p);

		return ret;
	}
};