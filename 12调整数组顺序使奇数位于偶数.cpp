/*
��ָoffer-��������˳��ʹ����λ��ż��
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������
�ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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