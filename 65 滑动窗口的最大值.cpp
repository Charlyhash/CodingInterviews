/*
��ָoffer �������ڵ����ֵ

��Ŀ����
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������
{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ
{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� 
{2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��

����˼·:
��һ��˫�˶��У��洢���ܵ����ֵ���±꣬ÿ�θ���������С�
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
			{//�Ӻ������ε����ȵ�ǰ����С��Ԫ�أ���Ϊ��ЩԪ�ز�����Ϊ���ֵ
				while (!q.empty() && num[i] >= num[q.back()])
					q.pop_back();
				q.push_back(i);
			}
			for (size_t i = size; i < num.size(); ++i)
			{
				ret.push_back(num[q.front()]);
				//�����ȵ�ǰԪ��С�Ķ��к����Ԫ��
				while (!q.empty() && num[i] >= num[q.back()])
					q.pop_back();
				//�����������ڵ��±�
				if (!q.empty() && q.front() <= (int)(i - size))
					q.pop_front();
				//�����
				q.push_back(i);
			}
			//���һ��Ԫ��δ����
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