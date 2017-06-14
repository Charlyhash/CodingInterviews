/*
leetcode ��1+2+3+...+n

��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ�
�����ж���䣨A?B:C����
����˼·��

*/

#include<iostream>
using namespace std;

//1. ʹ�ù��캯��
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

//2. ����&&�Ķ�·����
/*
��n=0, (n>0)&&((sum+=Sum_Solution(n-1))>0)ִֻ��ǰ����жϣ�Ϊfalse��Ȼ��ֱ�ӷ���0��
��n>0ʱ���ݹ����Sum_Solution
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