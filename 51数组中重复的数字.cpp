/*
剑指offer 数组中重复的数字

题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道
有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，
如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。

解题思路：
1. 用set保存，时间复杂度为O(n),空间复杂度为O(n)
2. 第i个位置存放数字i,基于交换：扫描数组，下标为i的数字，首先比较这个数字m是否等于i,如果相等继续
扫描，否则不是，就与第m个数字比较， 如果相等就找到了第一个重复的数字，否则就把第i个和第m个交换，
接下来重复比较。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0)
			return false;
		for (int i = 0; i < length; ++i)
		{
			//应该在[0,len)之间
			if (numbers[i] < 0 || numbers[i] > length - 1)
				return false;
		}
		//核心算法
		for (int i = 0; i < length; ++i)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				//交换
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}

		return false;
	}
};

int main()
{
	Solution sol;
	const int length = 7;
	int numbers[length] = { 2,3,1,0,2,5,3 };
	int dup = 0;
	cout << sol.duplicate(numbers, length, &dup) << endl;
	cout << dup << endl;

	return 0;
}