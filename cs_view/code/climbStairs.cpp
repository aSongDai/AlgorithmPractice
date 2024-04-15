#include <iostream>
#include <vector>

class Solution
{
public:

	/*
	// 时间超限
	int climbStairs(int n)
	{
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
	*/

	int climbStairs(int n)
	{
		/*
		// 使用是只有两个数会被用到，优化后 空间复杂度为 O(1)
		std::vector<int> dp(n);
		dp[0] = 1;
		dp[1] = 2;
		*/
		int first = 1, second = 2, result = 0;
		for (int i = 2; i < n; ++i)
		{
			result = first + second;
			first = second;
			second = result;
		}
		return result;
	}
};