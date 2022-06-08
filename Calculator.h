#pragma once
#include <iostream>
#include <string>
#include <vector>

class Calculator
{
public:
	Calculator()
		:
		Bpoint{0u,0u}
	{
		std::cout << "Enter an expression." << std::endl;
		std::cin >> MainString;
		RawString = MainString;
	};
	~Calculator() = default;
	std::string GetRawString() const;
	std::vector<std::string> Separator(const std::string& string) const;
	void PriorityChecker(const std::string& op);
	std::string BracketsChecker(const std::string& string);
	float Calculate(const std::vector<std::string>& result, const std::string& op, const unsigned int& order) const;
	void CalLoop(std::vector<std::string>& r);
	bool CheckFirstChar() const;
	float MainLoop();
private:
	std::string MainString;
	std::string RawString;
	std::string CheckString;
	unsigned int Bpoint[2];
	std::vector<unsigned int> Priority;
	std::vector<unsigned int> P1pos;
	std::vector<unsigned int> P0pos;
};

