/*
��ָoffer
��Ŀ���⣺��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

�����������Ͻǵ����ֿ�ʼ�Ƚϣ�����������������ôֱ�ӷ��أ���������������
��ôһ������һ����ߣ����С���������һ������һ�����档
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if (array.size() == 0)
			return false;
		int row = array.size();
		int col = array[0].size();
		int res = false;
		int j = col - 1; 
		int i = 0;
		while(i >= 0 && i < row && j >= 0 && j < col)
		{
			if (target == array[i][j])
				return true;
			else if (target < array[i][j])
				--j;
			else
				++i;
		}

		return res;
	}
};

void TEST()
{
	Solution sol;
	vector<vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13}};
	cout << sol.Find(7, array) << endl;
	cout << sol.Find(3, array) << endl;
	cout << sol.Find(20, array) << endl;
}

int main()
{
	TEST();

	return 0;

}