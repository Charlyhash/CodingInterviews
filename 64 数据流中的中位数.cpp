/*
剑指offer 数据流中的中位数

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

解题思路：
用两个堆, 一个最大堆和一个最小堆。要保证最大堆里的数都小于最小堆里的数，且两个堆中元素个数差不超过1，这样，
可以在O(1)的时间里得到中值。为了保证两个堆的特性，插入的规则如下：
1. 当最小堆插入的数字小于最小堆中最小的元素时插入到最小堆中，否则插入到最大堆中
2. 如果最大堆中元素比最小堆少2个，则最大堆加入最小堆中最小的元素，最小堆弹出最小元素O(logn)
3. 如果最小堆比最大堆元素少1个，则最小堆加入最大堆中最大的元素，最大堆弹出最大的元素O(logn)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
private:
	priority_queue<int, vector<int>, less<int>> p;
	priority_queue<int, vector<int>, greater<int>> q;
public:
	void Insert(int num)
	{
		if (p.empty() || num < p.top())
			p.push(num);
		else
			q.push(num);
		if (p.size() == q.size() + 2)
		{
			q.push(p.top());
			p.pop();
		}
		if (p.size() == q.size() - 1)
		{
			p.push(q.top());
			q.pop();
		}
	}

	double GetMedian()
	{
		if ((q.size() + p.size()) & 0x1)
			return (p.top());
		else
			return (p.top() + q.top()) / 2.0;
	}
};

int main()
{
	Solution sol;
	vector<int> v{ 3,2,1,4,5,6,8 };
	for (auto num : v)
	{
		sol.Insert(num);
		cout << sol.GetMedian() << endl;
	}
	
	return 0;
}

