#include <vector>
#include <map>	
#include <iostream>

class Solution
{
public:
	// �о�ȷʵ����ʹ��̰�� �����㣬 ÿ�ζ�ѡ������������ m ���ʽ������Ź���
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

	std::cout << "Ŀǰ���ʽ��ܹ����Ź��ʵ�����Ϊ�� " << solution.monthsOfSalary(denominations, counts, m) << "��" << std::endl;

}