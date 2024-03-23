/*
	描述：
		输入一个C风格字符串	类型 char指针

		将这个C风格字符串中的单词翻转
	
	例如：
		This is a C string.
		输入：string C a is This.

	要求：
		尽可能低的空间复杂度
*/

#include <vector>	
#include <string>

class Solution
{
public:
	/*
		char[]			the length must have n+1, because it have to save '\0'
		char*			the end of this is '\0'
	*/
	const char* reverse(char* sentence)
	{
		// use string, O(n) space 
		std::string str(sentence);
		int n = str.size(), i = 0;
		std::vector<int> zeroPos;
		const char* result;

		for (const auto ch : str)
		{
			if (ch == ' ')
			{
				zeroPos.push_back(i);
			}
			++i;
		}

		result = str.c_str();
		return result;
	}
};