#include <vector>	
#include <iostream>	
#include <algorithm>

class Solution
{
public:
	int twoCitySchedCost(std::vector<std::vector<int>>& costs)
	{
		// sort
		std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b)
			{
				return a[0] - a[1] < b[0] - b[1];
			});

		int result = 0;
		int n = costs.size() / 2;

		for (int i = 0; i < n; ++i)
			result += costs[i][0] + costs[n + i][1];
		return result;

	}
};