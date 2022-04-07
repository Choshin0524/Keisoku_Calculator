#include "Calculator.h"
std::vector<std::string> Calculator::Separator(const std::string& string) const
{
	std::vector<unsigned int> spoint = {0u};
	std::vector<std::string> result;
	std::string op;

	for (int i = 0; i < string.length(); i++)
	{
		if (string[i] == '+' || string[i] == '-' ||
			string[i] == '*' ||	string[i] == '/')
			spoint.push_back(i);
	}
	result.push_back(string.substr(spoint[0], spoint[1]));
	for (int i = 1; i < spoint.size(); i++)
	{
		op += string[spoint[i]];
		if (i != spoint.size() - 1)
			result.push_back(string.substr(spoint[i] + 1, spoint[i + 1] - spoint[i] - 1));
		else if (i = spoint.size() - 1) result.push_back(string.substr(spoint[i] + 1));
	}
	result.push_back(op);
	return result;
}

std::string Calculator::GetRawString() const
{
	return RawString;
}

void Calculator::PriorityChecker(const std::string& op)
{
	Priority = {};
	P1pos = {};
	P0pos = {};
	for (int i = 0; i < op.length(); i++)
	{
		if (op[i] == '+' || op[i] == '-') Priority.push_back(1u);
		else if (op[i] == '*' || op[i] == '/') Priority.push_back(0u);
	}
	for (int i = 0; i < Priority.size(); i++)
	{
		if (Priority[i] == 1u) P1pos.push_back(i);
		else if (Priority[i] == 0u) P0pos.push_back(i);
	}
}

std::string Calculator::BracketsChecker(const std::string& string)
{
	for (int i = 0; i < string.length(); i++)
	{
		if (string[i] == '(') Bpoint[0] = i;
	}
	for (int i = Bpoint[0]; i < string.length(); i++)
	{
		if (string[i] == ')')
		{
			Bpoint[1] = i;
			break;
		}
	}
	return string.substr(Bpoint[0] + 1, Bpoint[1] - Bpoint[0] - 1);
}

float Calculator::Calculate(const std::vector<std::string>& result,
	const std::string& op, const unsigned int& order) const
{
	switch (op[order])
	{
	case '+':
		return std::stof(result[order]) + std::stof(result[order + 1]);
	case '-':
		return std::stof(result[order]) - std::stof(result[order + 1]);
	case '*':
		return std::stof(result[order]) * std::stof(result[order + 1]);
	case '/':
		return std::stof(result[order]) / std::stof(result[order + 1]);
	}
}

void Calculator::CalLoop(std::vector<std::string>& r)
{
	auto op = r.back();
	PriorityChecker(op);
	while (op.length() > 0 && P0pos.size() != 0)
	{
		float Rbuffer = Calculate(r, op, P0pos[0]);
		r.erase(r.begin() + P0pos[0], r.begin() + P0pos[0] + 2);
		op.erase(P0pos[0], 1);
		r.insert(r.begin() + P0pos[0], std::to_string(Rbuffer));
		PriorityChecker(op);
	}
	while (op.length() > 0 && P1pos.size() != 0)
	{
		float Rbuffer = Calculate(r, op, P1pos[0]);
		r.erase(r.begin() + P1pos[0], r.begin() + P1pos[0] + 2);
		op.erase(P1pos[0], 1);
		r.insert(r.begin() + P1pos[0], std::to_string(Rbuffer));
		PriorityChecker(op);
	}
}

bool Calculator::CheckFirstChar() const
{
	switch (MainString[0])
	{
	case 'e':
		return true;
	case 'c':
		return false;
	case 'L':
		std::cout << "Hello" << std::endl;
		return true;
	}
	
}

float Calculator::MainLoop()
{
	while (MainString.find('(') != -1)
	{
		CheckString = BracketsChecker(MainString);
		auto r = Separator(CheckString);
		CalLoop(r);
		MainString.erase(Bpoint[0], Bpoint[1] - Bpoint[0] + 1);
		MainString.insert(Bpoint[0], r[0]);
	}
	auto r = Separator(MainString);
	CalLoop(r);
	return std::stof(r[0]);
}