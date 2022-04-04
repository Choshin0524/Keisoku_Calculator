#include "Calculator.h"
std::vector<std::string> Calculator::Separator() const
{
	unsigned int spoint = 0u;
	std::vector<std::string> result;
	std::string op = "";

	for (int i = 0; i < MainString.length(); i++)
	{
		if (MainString[i] == '+' ||
			MainString[i] == '-' ||
			MainString[i] == '*' ||
			MainString[i] == '/')
		{
			spoint = i;
		}
	}
	op[0] = MainString[spoint];
	result = { MainString.substr(0, spoint), op, MainString.substr(spoint + 1) };
	return result;
}

std::string Calculator::GetMainString() const
{
	return MainString;
}

float Calculator::Calculate(const std::vector<std::string>& result) const
{
	switch (result[1][0])
	{
	case '+':
		return std::stof(result[0]) + std::stof(result[2]);
	case '-':
		return std::stof(result[0]) - std::stof(result[2]);
	case '*':
		return std::stof(result[0]) * std::stof(result[2]);
	case '/':
		return std::stof(result[0]) / std::stof(result[2]);
	}
}