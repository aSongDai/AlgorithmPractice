#include <string>
#include <vector>	

class Solution
{
public:
	std::string countAndSay(int n)
	{
		if (n == 1)
		{
			return "1";
		}

		std::string s = countAndSay(n - 1);

		std::string res;

		int count = 1;
		char pre = s[0];
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == pre)
			{
				count++;
				continue;
			}
			else
			{
				res.push_back(count + '0');
				res.push_back(pre);
				pre = s[i];
				count = 1;
			}
		}
		res.push_back(count + '0');
		res.push_back(pre);
		

		return res;
	}
};