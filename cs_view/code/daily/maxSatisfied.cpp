#include <vector>	

class Solution
{
public:
	int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes)
	{
		// ����ת���� ��ʵ���������������������, ��������Ϊ�̶����ڵĳ���Ϊ minutes
		int total = 0;
		int n = customers.size();		// ��ʱ��

		for (int i = 0; i < n; ++i)
		{
			if (!grumpy[i])
			{
				total += customers[i];
			}
		}

		int increase = 0;
		for (int i = 0; i < minutes; i++)
		{
			increase += customers[i] * grumpy[i];
		}

		int maxIncrease = increase;
		for (int i = minutes; i < n; ++i)
		{
			increase = increase - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
			maxIncrease = std::max(maxIncrease, increase);
		}

		return total + maxIncrease;

	}
};