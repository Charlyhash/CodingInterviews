/*
题目描述：
牛牛现在有一个n个数组成的数列,牛牛现在想取一个连续的子序列,并且这个子序列还必须得满足:
最多只改变一个数,就可以使得这个连续的子序列是一个严格上升的子序列,牛牛想知道这个连续子
序列最长的长度是多少。

输入描述:
输入包括两行,第一行包括一个整数n(1 ≤ n ≤ 10^5),即数列的长度;
第二行n个整数a_i, 表示数列中的每个数(1 ≤ a_i ≤ 10^9),以空格分割。


输出描述:
输出一个整数,表示最长的长度。

输入例子:
6
7 2 3 1 5 6

输出例子:
5
解题思路:
动态规划+判断。
以v[i]开始的最长上升子序列dp1, v[i]<v[i+1]时，dp1[i] = dp1[i+1]+1;否则dp1[i]=1;
以v[i]结尾的最长上升子序列dp2, v[i]>v[i-1]时，dp2[i] = dp2[i-1]+1;否则dp2[i]=1;
对于每一个位置i
i=0时，maxLen=dp1[1]+1
i=n-1时，maxLen = dp2[n-2]+1
其他:
v[i-1]+1 < v[i+1], maxLen = dp1[i+1]+dp2[i-1]+1否则：
maxLen = max(dp1[i+1],dp2[i-1])+1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		if (n == 0 || n == 1)
		{
			cout << n << endl;
			continue;
		}
		vector<int> dp1( n, 0 ); //dp1[i]是以v[i]开始的最长上升子序列
		vector<int> dp2( n, 0 ); //dp2[i]是以v[i]结尾的最长上升子序列

		dp1[n - 1] = 1;
		for (int i = n - 2; i >= 0; --i)
		{
			if (v[i] < v[i + 1])
				dp1[i] = dp1[i + 1] + 1;
			else
				dp1[i] = 1;
		}

		dp2[0] = 1;
		for (int i = 1; i < n - 1; ++i)
		{
			if (v[i] > v[i - 1])
				dp2[i] = dp2[i - 1] + 1;
			else
				dp2[i] = 1;
		}

		int ret = 1;
		int m = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (i == 0)
				m = dp1[i + 1] + 1;
			else if (i == n - 1)
				m = dp2[i - 1] + 1;
			else if (v[i - 1] + 1 < v[i + 1])
				m = dp1[i + 1] + dp2[i - 1] + 1;
			else
				m = max(dp1[i + 1], dp2[i - 1]) + 1;
			if (m > ret)
				ret = m;
		}

		cout << ret << endl;
	}

}