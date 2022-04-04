#pragma once
#include <iostream>
#include <string>
#include <vector>

class Calculator
{
public:
	Calculator()
	{
		std::cout << "Enter an expresssion." << std::endl;
		std::cin >> MainString;
	};
	~Calculator() = default;
	std::string GetMainString() const;
	std::vector<std::string> Separator(const std::string& string) const;
	void PriorityChecker(const std::string& op);
	float Calculate(const std::vector<std::string>& result, const unsigned int& order) const;
	float CalLoop();
private:
	std::string MainString;
	std::vector<unsigned int> Priority;
	std::vector<unsigned int> P1pos;
	std::vector<unsigned int> P0pos;
};

