#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	/*
		给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
	*/
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
	{
		// use hash

		std::unordered_map<std::string, std::vector<std::string>> mp;

		std::vector<std::vector<std::string>> result;

		for (const auto& str : strs)
		{
			auto key = str;
			std::sort(key.begin(), key.end());
			mp[key].emplace_back(str);
		}

		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			result.emplace_back(it->second);
		}
		return result;

	}
};