/*
��ָoffer��������ֻ����һ�ε�����
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ��
�����֡�

����˼·��
1. ��set��ţ��������飬�������set�У��ͼ��룬�����set��ɾ�������
2. �����е����ֻ����㣬���Ϊһ�������ҵ������Ϊ1�����λ����������������λ�Ƿ�Ϊ1,
�������Ϊ���顣��ʱ�ֵõ����鶼��ֻ��һ����һ�������ˡ�
�������������ֱ�����㣬��ô��õĽ��������������ͬ�����ˡ�
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size() < 2)
			return;
		int orRes = 0;
		for (size_t i = 0; i < data.size(); ++i)
			orRes ^= data[i];
		int oneIndex = firstOfOne(orRes);
		*num1 = *num2 = 0;
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (isBitOne(data[i], oneIndex))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}

	}
private:
	int firstOfOne(int num)
	{
		if (num == 0)
			return -1;
		int index = 0;
		while ((num & 1) == 0)
		{
			num = num >> 1;
			++index;
		}

		return index;	
	}

	bool isBitOne(int num, int index)
	{
		num = num >> index;
		return num & 1;
	}
};

int main()
{
	Solution sol;
	vector<int> v{ 2,4,3,6,3,2 };
	int num1 = 0, num2 = 0;
	sol.FindNumsAppearOnce(v, &num1, &num2);

	cout << num1 << " " << num2 << endl;

	return 0;
}