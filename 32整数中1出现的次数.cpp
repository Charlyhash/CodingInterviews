/*
剑指offer-整数中1出现的次数（从1到n整数中1出现的次数）

题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下
1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

解题思路：

There are three cases:
Case 1: UVW0XYZ
count = count
e.g., 109: (10+1)*1 + 0*10 + (9+1)
Case 2: UVW1XYZ
count += XYZ + 1
e.g., 1456: (145+1)*1 + (14+1)*10 + (1+1)*100 + (456+1)
Case 3: UVW?XYZ (? >= 2)
count += (UVW + 1) * 1000        (1000 is determined by the digit of ?)
e.g., 229: (22+1)*1 + (2+1)*10 + (0+1)*100

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int res = 0; int a = 1; int b = 1;
		while (n > 0)
		{
			cout << (n + 8) / 10 * a << "," << (n % 10 == 1)*b << endl;
			//(n + 8) / 10表示要这个数>=2，那么就是(左边的数+1)*1 个
			//(n % 10 == 1)*b表示这一位如果为1，那么这一位上的个数还有加上（右边的数+1）
			//其他情况：这一位为0，那么就不可能有这一位为1
			res += (n + 8) / 10 * a + (n % 10 == 1)*b;
			b += n % 10 * a;//累计的右边的数
			a *= 10;//累计的左边的数
			n /= 10;
		}

		return res;
	}
};

int main()
{
	Solution sol;
	cout << sol.NumberOf1Between1AndN_Solution(10) << endl;

	return 0;
}