#include <string>	
#include <vector>
#include <unordered_map>


class Solution
{
public:
	// 设计时间复杂度为 O(m+n) 的算法
	std::string minWindow(std::string s, std::string t)
	{
		int lenS = s.size(), lenT = t.size();
		if (lenS < lenT) return "";
		
		for (const auto& ch : t)
			++target[ch];

		int len = INT_MAX, l = 0, r = -1;
		int resL = -1, resR = -1;

		while (r < lenS)
		{
			if (target.find(s[++r]) != target.end())
			{
				++origin[s[r]];
			}
			while (check() && l <= r)
			{
				if (r - l + 1 < len)
				{
					len = r - l + 1;
					resL = l;
				}
				// 缩短结果
				if (target.find(s[l]) != target.end())
				{
					--origin[s[l]];
				}
				++l;
			}
		}
		return resL == -1 ? "" : s.substr(resL, len);
	}
private:
	bool check()
	{
		for (const auto& [ch, count] : target)
		{
			if (origin[ch] < count)
				return false;
		}
		return true;
	}

private:
	std::unordered_map<char, int> target, origin;
};