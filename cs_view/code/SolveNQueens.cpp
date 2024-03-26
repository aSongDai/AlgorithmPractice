#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

class Solution
{
public:
	/*
		
	*/
	std::vector<std::vector<std::string>> solveNQueens(int n)
	{
		std::vector<std::vector<std::string>> result;

		std::vector<int> queenRowInd(n, -1);				// record queen index in each row
		std::unordered_set<int> column;						// record the status of column
		std::unordered_set<int> slash;						// record the status of slash
		std::unordered_set<int> backSlash;					// record the status of backslash

		backTrace(result, queenRowInd, n, 0, column, slash, backSlash);		

		return result;
	}

	void backTrace(std::vector<std::vector<std::string>>& result, std::vector<int>& queenRowInd, int n, int row,
		std::unordered_set<int>& column, std::unordered_set<int>& slash, std::unordered_set<int>& backSlash)
	{
		if (n == row)
		{
			generateResult(result, queenRowInd);
		}
		else
		{
			// search a space which use
			for (int i = 0; i < n; ++i)
			{
				if (column.find(i) != column.end())
				{
					continue;
				}
				
				int slashSum = row - i;
				if (slash.find(slashSum) != slash.end())
				{
					continue;
				}

				int backSlaSum = row + i;
				if (backSlash.find(backSlaSum) != backSlash.end())
				{
					continue;
				}

				queenRowInd[row] = i;
				column.insert(i);
				slash.insert(slashSum);
				backSlash.insert(backSlaSum);
				backTrace(result, queenRowInd, n, row + 1, column, slash, backSlash);
				queenRowInd[row] = -1;
				column.erase(i);
				slash.erase(slashSum);
				backSlash.erase(backSlaSum);

			}
		}
	}

	void generateResult(std::vector<std::vector<std::string>>& result, std::vector<int> const & queenRowInd)
	{
		std::vector<std::string> ans;
		int queenNum = queenRowInd.size();
		for (int i = 0; i < queenNum; ++i)
		{
			std::cout << "Queen row [ " << i << " ] index is: "<< queenRowInd[i] << "." << std::endl;
			std::string row(queenNum, '.');
			row[queenRowInd[i]] = 'Q';
			ans.push_back(row);
			std::cout << "rwo ["<< i << "] is " << row.data() << std::endl;
		}
		result.push_back(ans);
	}
};