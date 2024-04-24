#include <vector>	

class Solution
{
public:
	int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes)
	{
		// 问题转化， 其实就是求最大连续子数组呗, 限制条件为固定窗口的长度为 minutes
		int total = 0;
		int n = customers.size();		// 总时长

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