/*
剑指offer-二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的
结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个
数字都互不相同。

解题思路：对于二叉搜索树，其后序遍历的最后一个元素为根节点。
因此可以通过递归的方法将数组分为两部分，继续递归。其中分得
两个数组一个全部小于根节点，一个全部大于根节点。
*/

#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
private:
	bool Help(vector<int>& sequence, int l, int r)
	{
		if (l >= r)
			return true;
		int i = l;
		while (sequence[i] < sequence[r] && i < r)
			++i;
		for (int j = i; j < r; ++j)
			if (sequence[j] < sequence[r])
				return false;

		return Help(sequence, l, i - 1) && Help(sequence, i, r-1);
	}
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;

		return Help(sequence, 0, sequence.size() - 1);
	}
};

int main()
{
	vector<int> s{ 4,8,6,12,16,14,10 };
	Solution sol;
	cout << sol.VerifySquenceOfBST(s) << endl;

	return 0;
}