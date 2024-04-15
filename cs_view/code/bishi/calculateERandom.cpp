#include <vector>
#include <iostream>

/*
	��������
		��Ҫ��ȡ n ��������� �� i ��������ĳ�ȡ������ [li, ri]�� ��������������е��������е�һ��
		����������������ÿ�����ֵĸ�����ͬ��
	�ʣ�
		�� n �����������Сֵ������ֵ�Ƕ���
			
			������ һ����ɢ���������������ֵ����ʵ����ÿ�ο��ܵĽ�������������ʵ��ܺ͡�

	���룺
		�������룺
		��һ��	һ�������� n			��ʾ��ȡ n �������
		�ڶ���	n ��������			�ֱ��ʾ�� n �����������߽�
		������	n ��������			�ֱ��ʾ�� n ����������б߽�
	�����
		һ�� double ���͵ĸ�����
*/

class Solution
{
public:
	double getERandom(int n, const std::vector<int>& l, const std::vector<int>& r)
	{
		double result = 0.0;

		for (int i = 0; i < n; ++i)
		{
			result += (1 / (r[i] - l[i] + 1)) * l[i];
		}

		return result;
	}
};



int main()
{
	Solution solution;
	int n;
	std::cin >> n;

	std::vector<int> l(n), r(n);

	for (int i = 0; i < n; ++i)
		std::cin >> l[i];
	for (int i = 0; i < n; ++i)
		std::cin >> r[i];

	std::cout << "n �����������Сֵ������ֵ�ǣ� " << solution.getERandom(n, l, r) << std::endl;
	return 0;
}