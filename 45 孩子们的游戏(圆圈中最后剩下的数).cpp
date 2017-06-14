/*
剑指offer:孩子们的游戏(圆圈中最后剩下的数)

题目描述：
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客
的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大
圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列
唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续
0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的
“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？
(注：小朋友的编号是从0到n-1)

解题思路：
剩余的数为f(n,m),第一次剔除的数为k=(m-1)%n。之后对应关系为：
k+1 ---> 0
k+2 ---> 1
...
n-1 ---> n-k-2
...
k-1 ---> n-1
从右到左的映射为g(x) = (x + k + 1)%n
那么f(n-1, m)表示剔除上一个后剩余的数，我们映射到上一个数为：(f(n-1,m)+k+1)%n
由此得到递推关系：
f(n,m) = (f(n-1,m)+k+1)%n = (f(n-1,m)+m)%n(n>1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		int last = 0; //刚开始剩余的必定为0
		for (int i = 2; i <= n; ++i)
		{
			last = (last + m) % i;//向后递推
		}

		return last;
	}
};

int main()
{
	Solution sol;
	cout << sol.LastRemaining_Solution(5, 3) << endl;

	return 0;
}