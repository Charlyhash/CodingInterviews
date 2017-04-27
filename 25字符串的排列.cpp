/*
剑指offer-字符串的排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串
abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和
cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。


解题思路：递归
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> ret;
		if (str.size() == 0)
			return ret;
		DFS(ret, 0, str);

		return ret;
	}

	void DFS(vector<string>& ret, int k, string str)
	{
		if (k == str.size() - 1) //退出条件
			ret.push_back(str);
		unordered_set<char> uset;//不要重复
		sort(str.begin() + k, str.end());//排序
		for (int i = k; i < str.size(); ++i)
		{
			if (uset.find(str[i]) == uset.end())
			{
				uset.insert(str[i]);
				swap(str[i], str[k]);
				DFS(ret, k + 1, str);
				swap(str[i], str[k]);//复位
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<string> ret = sol.Permutation("aba");

	for (auto str : ret)
		cout << str << endl;
	return 0;
}