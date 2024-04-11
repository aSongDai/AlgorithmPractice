#include <string>	
#include <unordered_map>

enum class State
{
	STATE_INITIAL,
	STATE_SIGN,
	STATE_INTEGER,
	STATE_DOT,
	STATE_DOT_WITHOUT_INT,
	STATE_FRACTION,
	STATE_EXP,
	STATE_EXP_SIGN,
	STATE_EXP_NUMBER,
	STATE_END
};

enum class CharType
{
	CHAR_SIGN,
	CHAR_NUMBER,
	CHAR_DOT,
	CHAR_EXP,
	CHAR_ILLEGAL
};

class Solution
{
public:
	/*
		从前往后，使用状态机来进行数据的状态转移
	*/
	bool isNumber(const std::string& s)
	{
		std::unordered_map<State, std::unordered_map<CharType, State>> transfer =
		{
			{State::STATE_INITIAL, {
				{CharType::CHAR_SIGN, State::STATE_SIGN},
				{CharType::CHAR_NUMBER, State::STATE_INTEGER},
				{CharType::CHAR_DOT, State::STATE_DOT_WITHOUT_INT}
			}},
			{State::STATE_SIGN, {
				{CharType::CHAR_NUMBER,State::STATE_INTEGER},
				{CharType::CHAR_DOT, State::STATE_DOT_WITHOUT_INT},
				}},
			{State::STATE_INTEGER, {
				{CharType::CHAR_NUMBER,State::STATE_INTEGER},
				{CharType::CHAR_DOT,State::STATE_DOT},
				{CharType::CHAR_EXP,State::STATE_EXP},
				}},
			{State::STATE_DOT, {
				{CharType::CHAR_NUMBER,State::STATE_FRACTION},
				{CharType::CHAR_EXP,State::STATE_EXP}
			}},
			{State::STATE_DOT_WITHOUT_INT, {
				{CharType::CHAR_NUMBER,State::STATE_FRACTION}
			}},
			{State::STATE_FRACTION, {
				{CharType::CHAR_NUMBER,State::STATE_FRACTION},
			{CharType::CHAR_EXP,State::STATE_EXP},
			}},
			{State::STATE_EXP, {
				{CharType::CHAR_SIGN,State::STATE_EXP_SIGN},
			{CharType::CHAR_NUMBER,State::STATE_EXP_NUMBER},
			}},
			{State::STATE_EXP_SIGN, {
				{CharType::CHAR_NUMBER,State::STATE_EXP_NUMBER}}},
			{State::STATE_EXP_NUMBER, {
				{CharType::CHAR_NUMBER,State::STATE_EXP_NUMBER}
			}},
		};

		State state = State::STATE_INITIAL;
		for (const auto ch : s)
		{
			CharType chType = toCharType(ch);
			if (transfer[state].find(chType) == transfer[state].end())
			{
				return false;
			}
			else
			{
				state = transfer[state][chType];
			}
		}

		return state == State::STATE_INTEGER || state == State::STATE_EXP_NUMBER
			|| state == State::STATE_DOT || state == State::STATE_FRACTION
			|| state == State::STATE_END;

	}

private:
	CharType toCharType(const char ch)
	{
		if (ch >= '0' && ch <= '9')
		{
			return CharType::CHAR_NUMBER;
		}
		else if (ch == '.')
		{
			return CharType::CHAR_DOT;
		}
		else if (ch == 'e' || ch == 'E')
		{
			return CharType::CHAR_EXP;
		}
		else if (ch == '-' || ch == '+')
		{
			return CharType::CHAR_SIGN;
		}
		else
		{
			return CharType::CHAR_ILLEGAL;
		}
	}
};






/*
	网龙 字符串转整数
*/

//{
//	std::string numStr = "200";
//	int result = 0;
//	int numLength = 3;
//	std::string::const_iterator ptr = numStr.begin();
//	while (ptr != numStr.end())
//	{
//		result += (*ptr + '0') * pow(10, --numLength);
//	}
//	return result;
//}