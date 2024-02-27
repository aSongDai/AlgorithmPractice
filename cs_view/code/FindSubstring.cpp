#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:

	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
	{
		std::vector<int> answer;

		int ls = s.size(), m = words.size(), n = words[0].size();	// ls -> length of s,   m -> number of words, n -> length of word


		// shi jian chao xian 
/*		for (int i = 0; i < ls && i + m * n < ls; ++i)
		{
			std::unordered_map<std::string, int> temp;
			for (int j = 0; j < m; ++j)
			{
				// add m words from s
				++temp[s.substr(i + j * m, n)];
			}

			for (const auto& word : words)
			{
				if (--temp[word] == 0)
				{
					temp.erase(word);
				}
			}
			
			if (temp.empty())	answer.push_back(i);

		}
*/

		for (int i = 0; i < n && i + m * n <= ls; ++i)
		{
			// add window
			std::unordered_map<std::string, int> temp;
			for (int j = 0; j < m; ++j)
			{
				++temp[s.substr(i + j * n, n)];
			}

			for (const auto& word : words)
			{
				if (--temp[word] == 0)
				{
					temp.erase(word);
				}
			}

			// shift window
			for (int start = i; start + n * m < ls; start += n)
			{
				if (start != i)
				{
					auto word = s.substr(start + (m - 1) * n, n);
					if (++temp[word] == 0)
					{
						temp.erase(word);
					}
					word = s.substr(start - n, n);
					if (--temp[word] == 0)
					{
						temp.erase(word);
					}
				}
				if (temp.empty())	answer.push_back(start);
			}
		}

		return answer;
	}
};