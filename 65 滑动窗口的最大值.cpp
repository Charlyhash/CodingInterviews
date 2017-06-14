/*
剑指offer 滑动窗口的最大值

题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组
{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为
{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

解题思路:
用一个双端队列，存储可能的最大值的下标，每次更新这个队列。
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> ret;
		deque<int> q;
		if (num.size() >= size && size >= 1)
		{
			for (size_t i = 0; i < size; ++i)
			{//从后面依次弹出比当前数字小的元素，因为这些元素不可能为最大值
				while (!q.empty() && num[i] >= num[q.back()])
					q.pop_back();
				q.push_back(i);
			}
			for (size_t i = size; i < num.size(); ++i)
			{
				ret.push_back(num[q.front()]);
				//弹出比当前元素小的队列后面的元素
				while (!q.empty() && num[i] >= num[q.back()])
					q.pop_back();
				//弹出超过窗口的下标
				if (!q.empty() && q.front() <= (int)(i - size))
					q.pop_front();
				//入队列
				q.push_back(i);
			}
			//最后一个元素未加入
			ret.push_back(num[q.front()]);
		}

		return ret;
	}
};

int main()
{
	vector<int> v{ 2,3,4,2,6,2,5,1 };
	Solution sol;
	vector<int> ret = sol.maxInWindows(v, 3);

	for (auto num : ret)
		cout << num << " ";
	cout << endl;

	return 0;
}