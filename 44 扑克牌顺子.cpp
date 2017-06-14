/*
��ָoffer �˿���˳��

��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,��
�٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С 
�����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ�
����2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������
LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��

����˼·�������򣬱������֣�ͳ��0���ֵĴ�����Ȼ�󿴿�ȱ��λ���ǲ������㹻���0����䡣
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