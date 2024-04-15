#include <vector>
#include <iostream>

/*
	任务描述
		需要抽取 n 个随机数， 第 i 个随机数的抽取区间是 [li, ri]， 即这个数是区间中的正整数中的一个
		在这个区间中随机到每个数字的概率相同。
	问：
		这 n 个随机数的最小值的期望值是多少
			
			期望： 一个离散型随机变量的期望值，是实验中每次可能的结果乘以其结果概率的总和。

	输入：
		三行输入：
		第一行	一个正整数 n			表示抽取 n 个随机数
		第二行	n 个正整数			分别表示这 n 个随机数的左边界
		第三行	n 个正整数			分别表示这 n 个随机数的有边界
	输出：
		一个 double 类型的浮点数
*/

class Solution
{
public:
	double getERandom(int n, const std::vector<int>& l, const std::vector<int>& r)
	{
		double result = 0.0;

		for (int i = 0; i < n; ++i)
		{
			result += (1 / (r[i] - l[i] + 1)) * l[i];
		}

		return result;
	}
};



int main()
{
	Solution solution;
	int n;
	std::cin >> n;

	std::vector<int> l(n), r(n);

	for (int i = 0; i < n; ++i)
		std::cin >> l[i];
	for (int i = 0; i < n; ++i)
		std::cin >> r[i];

	std::cout << "n 个随机数的最小值的期望值是： " << solution.getERandom(n, l, r) << std::endl;
	return 0;
}