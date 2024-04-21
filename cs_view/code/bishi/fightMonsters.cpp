/*
	题目描述：
		给定一个数列，表示每一个洞穴中怪物的数量，

	要求：
		计算出这个给定数列，能够击杀的最大怪物数量。不能连续击杀两个洞穴的怪物，否则算刷怪失败

	输入：
		一个数组，分别表示每个洞穴的怪物数量
	输出：
		一个整数，表示刷怪的数量
*/

#include <vector>
#include <iostream>

class Solution
{
public:
	/*
		思路：
			动态规划，初始状态为 nums[0] 的数值
			状态转移方程为：
				dp[i] = dp[i-2] + nums[i] 
				dp[i] = dp[i-1]
	*/
	int fightMonsters(std::vector<int>& nums)
	{
		int n = nums.size();
		std::vector<int> dp(n);
		dp[0] = nums[0];
		dp[1] = std::max(dp[0], nums[1]);

		for (int i = 2; i < n; ++i)
		{
			dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[n - 1];
	}
};