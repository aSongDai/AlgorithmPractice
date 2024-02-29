#include <vector>
#include <string>

class Solution
{
public:
	bool isMatch(std::string s, std::string p)
	{
		// dynamic programming 
		int m = s.size();
		int n = p.size();

		std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

		dp[0][0] = true;

		for (int i = 1; i <= n; ++i)
		{
			if (p[i - 1] == '*')
			{
				dp[0][i] = true;
			}
			else
			{
				break;
			}
		}

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				}
				else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};