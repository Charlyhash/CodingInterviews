/*
牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道
他最少可以把这个数组分为几段排序子序列.如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]
两个排序子序列,至少需要划分为2个排序子序列,所以输出2
输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。

输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
输入例子:
6
1 2 3 2 2 1
输出例子:
2

解题思路:
扫描数组，每次都扫描到递增或递减变化，记录其位置，继续扫描。
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int k = 0; k < n; ++k)
			cin >> v[k];
		if (n == 0 || n == 1) {
			cout << n << endl;
			continue;
		}
		int i = 1;
		int ret = 0;
		while (i < n)
		{
			//非递增
			if (v[i] < v[i - 1])
			{
				while (i < n && v[i] <= v[i - 1])
					++i;
				++ret;
			}
			//非递减
			else if (v[i] > v[i - 1])
			{
				while (i < n && v[i] >= v[i - 1])
					++i;
				++ret;
			}
			//相等就要退出
			if (i == n - 1)
			{
				++ret;
				break;
			}
			++i;
		}

		cout << ret << endl;
	}
}