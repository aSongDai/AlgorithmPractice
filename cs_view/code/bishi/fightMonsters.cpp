/*
	��Ŀ������
		����һ�����У���ʾÿһ����Ѩ�й����������

	Ҫ��
		���������������У��ܹ���ɱ������������������������ɱ������Ѩ�Ĺ��������ˢ��ʧ��

	���룺
		һ�����飬�ֱ��ʾÿ����Ѩ�Ĺ�������
	�����
		һ����������ʾˢ�ֵ�����
*/

#include <vector>
#include <iostream>

class Solution
{
public:
	/*
		˼·��
			��̬�滮����ʼ״̬Ϊ nums[0] ����ֵ
			״̬ת�Ʒ���Ϊ��
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