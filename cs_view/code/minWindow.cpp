#include <string>	
#include <vector>
#include <unordered_map>


class Solution
{
public:
	// ���ʱ�临�Ӷ�Ϊ O(m+n) ���㷨
	std::string minWindow(std::string s, std::string t)
	{
		int lenS = s.size(), lenT = t.size();
		if (lenS < lenT) return "";
		
		for (const auto& ch : t)
			++target[ch];

		int len = INT_MAX, l = 0, r = 0;
		int resL = -1, resR = -1;

		while (r < lenS)
		{
			if (origin.find(s[r]) != origin.end())
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
				// ���̽��
				if (origin.find(s[l]) != origin.end())
				{
					--origin[s[l]];
				}
				++l;
			}
			++r;
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