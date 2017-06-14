/*
剑指offer 扑克牌顺子

题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿
嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 
王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别
看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们
LL的运气如何。为了方便起见,你可以认为大小王是0。

解题思路：先排序，遍历数字，统计0出现的次数，然后看空缺的位置是不是有足够多的0来填充。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) 
	{
		if (numbers.size() != 5) 
			return false;
		sort(numbers.begin(), numbers.end());
		int zeroCount = 0;
		int i = 0;
		for (;i < 5 && numbers[i]==0; ++i)
		{
			++zeroCount;
		}
		if (zeroCount > 3)
			return true;
		int smallIdx = i;
		int bigIdx = smallIdx + 1;
		int gap = 0;
		while (bigIdx < 5)
		{
			if (numbers[smallIdx] == numbers[bigIdx])
				return false;
			gap += numbers[bigIdx] - numbers[smallIdx] -1;
			smallIdx = bigIdx;
			bigIdx++;
		}
		if (gap > zeroCount)
			return false;
		return true;
	}
};

int main()
{
	vector<int> v(5, 0);
	while (1) {
		for (int i = 0; i < 5; ++i)
			cin >> v[i];
		Solution sol;
		cout << sol.IsContinuous(v) << endl;
	}
	return 0;
}