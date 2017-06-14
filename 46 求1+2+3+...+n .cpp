/*
leetcode 求1+2+3+...+n

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及
条件判断语句（A?B:C）。
解题思路：

*/

#include<iostream>
using namespace std;

//1. 使用构造函数
class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static int GetSum()
	{
		return Sum;
	}
	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

private:
	static int N;
	static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Temp::Reset();
		Temp* t = new Temp[n];
		delete[] t;
		t = NULL;

		return Temp::GetSum();
	}
};

//2. 利用&&的短路特性
/*
当n=0, (n>0)&&((sum+=Sum_Solution(n-1))>0)只执行前面的判断，为false，然后直接返回0；
当n>0时，递归计算Sum_Solution
*/
class Solution1
{
public:
	int Sum_Solution(int n)
	{
		int sum = n;
		bool flag = (n > 0) && ((sum += Sum_Solution(n-1)) > 0);
		return sum;
	}
};

int main()
{
	Solution1 sol;
	cout << sol.Sum_Solution(5) << endl;

	return 0;
}