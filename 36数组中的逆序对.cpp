/*
��ָoffer-�����е������

��Ŀ����:�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ��
����ԡ�����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ����
���� �����P%1000000007
��������:
��Ŀ��֤�����������û�е���ͬ������
���ݷ�Χ��
	����%50������,size<=10^4
	����%75������,size<=10^5
	����%100������,size<=2*10^5


��������:
1,2,3,4,5,6,7,0

�������:
7

����˼·������������
1. �鲢����
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long InversePairsCore(vector<int> &data, vector<int> &copy, long start, long end) {
		if (start == end)  // copy: ��������
		{
			return 0;  // �ݹ���ֹ����
		}

		long mid = (start + end) / 2;
		long left = InversePairsCore(copy, data, start, mid); // �ݹ飬�鲢���򣬲����㱾���������
		long right = InversePairsCore(copy, data, mid + 1, end);
		long crossCount = 0;       // ��¼������������
		long i = mid, j = end, temp = end;  //i��ǰ�벿�ֵ��±꣬j����벿�ֵ��±꣬temp������������±�

		while (i >= start && j >= mid + 1) {   // ���ڽ��������ԣ���ͳ��һ�£�Ȼ�����ν��ϴ�ֵ�Ž���������
			if (data[i] > data[j]) {
				copy[temp--] = data[i--];
				crossCount += j - start - (mid - start);
			}
			else {
				copy[temp--] = data[j--];   // �����ڽ��������ԣ����ν��ϴ�ֵ�Ž���������
			}
		}
		while (i >= start) {
			copy[temp--] = data[i--];
		}
		while (j >= mid + 1) {
			copy[temp--] = data[j--];
		}
		return (left + right + crossCount) % 1000000007; //��ֵ����ʱ����, ��ֹ���
	}
	int InversePairs(vector<int> &data) {
		if (data.size() <= 1) return data.size();
		else {
			vector<int> copy(data);
			return InversePairsCore(copy, data, 0, data.size() - 1);
		}
	}
};

int main()
{
	Solution sol;
	vector<int> v{ 364,637,341,406,747,995,234,971,571,219,993,407,416,366,
		315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,
		588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,
		256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,
		259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,
		848,38,811,267,575 };
	cout << sol.InversePairs(v) << endl;

	return 0;
}
