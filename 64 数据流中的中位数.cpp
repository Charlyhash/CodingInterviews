/*
��ָoffer �������е���λ��

��Ŀ����
��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��

����˼·��
��������, һ�����Ѻ�һ����С�ѡ�Ҫ��֤�����������С����С�������������������Ԫ�ظ��������1��������
������O(1)��ʱ����õ���ֵ��Ϊ�˱�֤�����ѵ����ԣ�����Ĺ������£�
1. ����С�Ѳ��������С����С������С��Ԫ��ʱ���뵽��С���У�������뵽������
2. ���������Ԫ�ر���С����2���������Ѽ�����С������С��Ԫ�أ���С�ѵ�����СԪ��O(logn)
3. �����С�ѱ�����Ԫ����1��������С�Ѽ�������������Ԫ�أ����ѵ�������Ԫ��O(logn)
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

