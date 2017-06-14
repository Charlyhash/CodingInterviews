/*
��ָoffer �������ظ�������

��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪��
�м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬
������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��

����˼·��
1. ��set���棬ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)
2. ��i��λ�ô������i,���ڽ�����ɨ�����飬�±�Ϊi�����֣����ȱȽ��������m�Ƿ����i,�����ȼ���
ɨ�裬�����ǣ������m�����ֱȽϣ� �����Ⱦ��ҵ��˵�һ���ظ������֣�����Ͱѵ�i���͵�m��������
�������ظ��Ƚϡ�
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0)
			return false;
		for (int i = 0; i < length; ++i)
		{
			//Ӧ����[0,len)֮��
			if (numbers[i] < 0 || numbers[i] > length - 1)
				return false;
		}
		//�����㷨
		for (int i = 0; i < length; ++i)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				//����
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}

		return false;
	}
};

int main()
{
	Solution sol;
	const int length = 7;
	int numbers[length] = { 2,3,1,0,2,5,3 };
	int dup = 0;
	cout << sol.duplicate(numbers, length, &dup) << endl;
	cout << dup << endl;

	return 0;
}