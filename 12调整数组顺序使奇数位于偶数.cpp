/*
剑指offer-调整数组顺序使奇数位于偶数
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组
的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> tmp = array;
		int j = 0;
		for (int i = 0; i < tmp.size(); ++i)
			if (tmp[i] & 0x1)
				array[j++] = tmp[i];
		for (int i = 0; i < tmp.size(); ++i)
			if (!(tmp[i] & 0x1))
				array[j++] = tmp[i];
	}
};

int main()
{
	vector<int> v{ 1,3,5,4,2 };
	Solution sol;
	sol.reOrderArray(v);

	for (auto i : v)
		cout << i << " ";
	cout << endl;
}