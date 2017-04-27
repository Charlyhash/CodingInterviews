/*
��ָoffer-ջ��ѹ�롢��������
���������������У���һ�����б�ʾջ��ѹ��˳��
���жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��
ջ���������־�����ȡ���������1,2,3,4,5��ĳջ
��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ
���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���е�
�������С���ע�⣺���������еĳ�������ȵģ�

����˼·������ջ��Ȼ��ջ��Ԫ����ѹ�����з���λ��
�����Ƿ���ȣ�����Ⱦͼ�����ջ����ȵĻ����͵�����
�ٴ�����������С�
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder1(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int p1 = 0;
		int p2 = 0;
		while (p2 < popV.size())
		{
			if (s.empty())
			{
				if (p1 >= pushV.size())
					break;
				s.push(pushV[p1++]);
			}
			else
			{
				if (s.top() == popV[p2])
				{
					s.pop();
					p2++;
				}
				else
				{
					if (p1 >= pushV.size())
						break;
					s.push(pushV[p1++]);
				}
			}
		}
		
		return (p1 == pushV.size() && p2 == popV.size());
	}

	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() == 0)
			return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size();)
		{
			stack.push_back(pushV[i++]);
			while (j < popV.size() && stack.back() == popV[j])
			{
				++j;
				stack.pop_back();
			}
		}

		return stack.empty();
	}
};

int main()
{
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,2,3,1 };
	Solution sol;
	cout << sol.IsPopOrder(v1, v2) << endl;
}

