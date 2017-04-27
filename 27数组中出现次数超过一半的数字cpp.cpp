/*
剑指offer 数组中出现次数超过一半的数字。

题目大意：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入
一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度
的一半，因此输出2。如果不存在则输出0。

解题思路：由于出现的次数是超过半数的，那么遍历数组，记住当前数cur自出现的次数count和可能
的target.如果遍历的数为该数字，则count+1。否则count-1.如果count为0,就让遍历的数为cur.
这样最后的cur就是出现次数超过一半的数
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		int cur = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i)
		{
			if (count == 0)
			{
				cur = numbers[i];
				count = 1;
			}
			else 
			{
				if (cur == numbers[i])
					++count;
				else
					--count;
			}

			//cout << cur << ":" << count << endl;
		}
		//if (count == 0)
		//	return 0;
		int times = 0;
		for (int i = 0; i < numbers.size(); ++i)
			if (cur == numbers[i])
				++times;
		if (2 * times <= numbers.size())
			return 0;

		return cur;
	}
};

int main()
{
	vector<int> v{ 4,2,4,1,4,2 };
	Solution sol;
	cout << sol.MoreThanHalfNum_Solution(v) << endl;
	return 0;
}