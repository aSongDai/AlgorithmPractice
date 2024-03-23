#include <cstring>

class Solution
{
public:

	/*
		in:
			char* s = "abcd"

		return 
			"dcba"
	*/
	void reverseCString(char* words)
	{
		size_t n = strlen(words);

		int i = 0;
		while (i != n / 2)
		{
			swap(words + i, words + n - i - 1);
			++i;
		}

	}
private:
	void swap(char* a, char* b)
	{
		char temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
};