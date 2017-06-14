/*
剑指offer-把数组排成最小的数

题目大意：

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小
的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
	string PrintMinNumber(vector<int> numbers)
	{
		string ret;
		int len = numbers.size();
		if (len == 0)
			return ret;
		vector<string> vstring(len, "");
		for (int i = 0; i < len; ++i)
			vstring[i] = to_string(numbers[i]);

		struct cmp c;
		sort(vstring.begin(), vstring.end(), c);
		
		for (int i = 0; i < len; ++i)
			ret += vstring[i];

		return ret;
	}

private:
	struct cmp
	{
		bool operator() (const string& s1, const string& s2) const
		{
			string st1 = s1 + s2;
			string st2 = s2 + s1;
			return st1 < st2;
		}
	};
};

int main()
{
	Solution sol;
	vector<int> num{3,32,321};
	string ret = sol.PrintMinNumber(num);
	cout << ret << endl;


	return 0;
}