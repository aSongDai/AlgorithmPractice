#include <string>	
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


class Solution
{
public:
	/*
		backtrace
	*/
	/*
	std::string getPermutation(int n, int k)
	{
		std::vector<std::string> result;
		std::set<int> valid;				// need initialization
		std::string ans;

		for (int i = 0; i < n; ++i)
		{
			valid.insert(i + 1);
		}
		backTrace(result, valid, ans, n, k);
		return *(result.end() - 1);
	}
	*/

	// 
	std::string getPermutation(int n, int k)
	{
		std::string result; 

		std::set<int> valid;
		for (int i = 0; i < n; ++i)
		{
			valid.insert(i + 1);
		}

		std::vector<int> fac(n, 1);
		for (int i = 1; i < n; ++i)
		{
			fac[i] = fac[i - 1] * i;
		}

		singleAdd(result, valid, fac, k, n, 1);

		return result;
	}

private:

	void singleAdd(std::string& result, std::set<int>& valid, const std::vector<int>& fac, int& target, int n, int position)
	{
		if (valid.empty() || position > n)
		{
			return;
		}
		else
		{
			std::set<int>::iterator it = valid.begin();
			std::cout << position << "valid: " << std::endl;
			for (const auto& num : valid)
			{
				std::cout << num << '\t';
			}
			std::cout << std::endl;
			int index = target / fac[n - position];
			std::cout << "The position ["<< position << "] should be ["<< index + 1 <<"]" << std::endl;
			std::advance(it, index);
			valid.erase(it);

			result += *it + '0';
			target -= index * fac[n - position];
			++position;
			singleAdd(result, valid, fac, target, n, position);
		}
	}

	// time out.
	/*

	void backTrace(std::vector<std::string>& result, std::set<int>& valid, std::string& ans, int forn, int k)
	{
		if (result.size() == k)
			return;
		if (valid.empty())
		{
			std::cout << ans.data() << std::endl;
			// 
			result.push_back(ans);
		}
		else
		{
			for (int i = 0; i < forn; ++i)
			{
				std::set<int>::iterator it = valid.begin();
				std::advance(it, i);
				std::cout << "Now: " << *it << std::endl;
				int num = *it;
				ans += *it + '0';
				valid.erase(num);
				backTrace(result, valid, ans, forn - 1, k);
				ans.pop_back();
				valid.insert(num);
			}
		}
	}

	*/
};