#include <cstring>
#include <string>	

class Solution
{
public:
	/*
		Give a sentence, return a sentence which has been reversed.

		s.t.	in		->		I love aSong.
				out		->		aSong love I.
	*/

	void reverseSentence(char* sentence)
	{
		/*
			1. reverse all char in this sentence without '.'
			2. find space ' '
			3. reverse the word between two ' '
		*/

		int n = strlen(sentence);

		// swap sentence with out '.'
		int i = 0; 
		while (i < (n - 2) / 2)
		{
			swap(sentence + i, sentence + n - 2 - i);
		}

		// reverse chars in word
		char* begin = sentence, * end = sentence;
		
		int wordLen = 0;
		while (*end != '.')
		{
			wordLen = 0;
			int i = 0;
			// find ' '
			while (*end != ' ')
			{
				++wordLen;
				++end;
			}
			while (i < wordLen / 2)
			{
				swap(begin + i, end - 1 - i);
				++i;
			}
			begin = end + 1;
			end = end + 1;
		}
		for (int i = 0; i < wordLen / 2; ++i)
		{
			swap(begin + i, end - 1 - i);
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