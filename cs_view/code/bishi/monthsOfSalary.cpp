#include <vector>
#include <map>	
#include <iostream>

class Solution
{
public:
	// 感觉确实可以使用贪心 来计算， 每次都选择最少能满足 m 的资金来发放工资
	int monthsOfSalary(std::vector<int>& denominations, std::vector<int>& counts, int m)
	{
		int n = denominations.size();

		std::map<int, int> money;

		for (int i = 0; i < n; ++i)
		{
			money[denominations[i]] = counts[i];
		}

		int result = canGive(money, m);

		return result;
	}
private:

	int canGive(std::map<int, int>& money, int m)
	{
		int months = 0;
		auto iter = money.rbegin();
		while (iter != money.rend())
		{
			if (iter->first > m && iter->second)
			{
				--iter->second;
				++months;
				continue;
			}
			if (!iter->second)
				money.erase(iter->first);
			++iter;
		}
		while (findMinSum(money, m))
			++months;
		return months;
	}

	bool findMinSum(std::map<int, int>& money, int m)
	{

	}

};


int main()
{
	Solution solution;
	int n, m;

	std::cin >> n >> m;

	std::vector<int> denominations(n), counts(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> denominations[i] >> counts[i];
	}

	std::cout << "目前的资金能够发放工资的月数为： " << solution.monthsOfSalary(denominations, counts, m) << "月" << std::endl;

}