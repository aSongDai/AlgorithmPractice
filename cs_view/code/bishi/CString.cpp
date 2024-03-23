/*
	������
		����һ��C����ַ���	���� charָ��

		�����C����ַ����еĵ��ʷ�ת
	
	���磺
		This is a C string.
		���룺string C a is This.

	Ҫ��
		�����ܵ͵Ŀռ临�Ӷ�
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