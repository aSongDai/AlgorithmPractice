#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	/*
		����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
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