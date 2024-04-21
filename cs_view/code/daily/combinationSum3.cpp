#include <vector>
#include <numeric>

class Solution
{
public:
	std::vector<std::vector<int>> combinationSum3(int k, int n)
	{
		for (int mask = 0; mask < (1 << 9); ++mask)
		{
			if (check(mask, k, n))
				answer.push_back(temp);
		}
		return answer;
	}
private:
	bool check(int mask, int k, int n)
	{
		temp.clear();
		for (int i = 0; i < 9; ++i)
		{
			if ((1 << i) & mask)
				temp.push_back(i + 1);
		}
		return temp.size() == k && std::accumulate(temp.begin(), temp.end(), 0) == n;
	}

private:
	std::vector<int> temp;
	std::vector<std::vector<int>> answer;
};